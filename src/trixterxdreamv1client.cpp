
#include "trixterxdreamv1client.h"

#include <string>
#include <math.h>

trixterxdreamv1client::trixterxdreamv1client() { this->ConfigureResistanceMessages(); }

void trixterxdreamv1client::ResetBuffer() {
    // for the case of an invalid packet, if this was smart, it would store all the input
    // and backtrack to the first header bytes after the beginning.

    this->inputBuffer.clear();
    this->byteBuffer.clear();
}

trixterxdreamv1client::PacketState trixterxdreamv1client::ProcessChar(char c) {
    /* Packet content
     *                            6A 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
     * (00) Header ---------------+  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
     * (01) Steering ----------------+  |  |  |  |  |  |  |  |  |  |  |  |  |  |
     * (02) Unknown --------------------+  |  |  |  |  |  |  |  |  |  |  |  |  |
     * (03) Crank position ----------------+  |  |  |  |  |  |  |  |  |  |  |  |
     * (04) Right brake ----------------------+  |  |  |  |  |  |  |  |  |  |  |
     * (05) Left brake --------------------------+  |  |  |  |  |  |  |  |  |  |
     * (06) Unknown --------------------------------+  |  |  |  |  |  |  |  |  |
     * (07) Unknown -----------------------------------+  |  |  |  |  |  |  |  |
     * (08) Button flags ---------------------------------+  |  |  |  |  |  |  |
     * (09) Button flags ------------------------------------+  |  |  |  |  |  |
     * (0A) Crank revolution time (high byte) ------------------+  |  |  |  |  |
     * (0B) Crank revolution time (low byte) ----------------------+  |  |  |  |
     * (0C) Flywheel Revolution Time (high byte) ---------------------+  |  |  |
     * (0D) Flywheel Revolution Time (low byte) -------------------------+  |  |
     * (0E) Heart rate (BPM) -----------------------------------------------+  |
     * (0F) XOR of 00..0E------------------------------------------------------+
     */

    constexpr int headerLength = 2;
    constexpr int packetLength = 16;
    constexpr uint8_t header[] = {0x6, 0xA};

    uint8_t b;

    if (isdigit(c)) {
        b = c - '0';
    } else if (c >= 'a' && c <= 'f') {
        b = c - 'a' + '\xA';
    } else {
        this->ResetBuffer();
        return Invalid;
    }

    // make sure the first 2 bytes are the header '6','a'
    if (this->byteBuffer.empty() && this->inputBuffer.size() < headerLength && b != header[this->inputBuffer.size()]) {
        this->inputBuffer.clear();
        return None;
    }

    if (this->inputBuffer.size() == 1) {
        this->byteBuffer.push_back((this->inputBuffer.back() << 4) + b);
        this->inputBuffer.clear();
    } else
        this->inputBuffer.push_back(b);

    if (this->byteBuffer.size() == packetLength) {
        // Validate the packet - the last byte should the XOR of the 1st 15.
        b = 0;
        for (int i = 0, limit = packetLength - 1; i < limit; i++)
            b ^= this->byteBuffer[i];

        if (b != this->byteBuffer.back()) {
            // invalid checksum
            this->ResetBuffer();
            return Invalid;
        }

        return Complete;
    }

    return Incomplete;
}

void trixterxdreamv1client::ConfigureResistanceMessages() {
    resistanceMessages = new uint8_t *[251];

    for (uint8_t level = 0; level <= 250; level++) {
        unsigned char *message = new uint8_t[6];
        resistanceMessages[level] = message;

        message[5] = message[0] = 0x6a;
        message[5] |= message[1] = level;
        message[5] |= message[2] = (level + 60) % 255;
        message[5] |= message[3] = (level + 90) % 255;
        message[5] |= message[4] = (level + 120) % 255;
    }
}

bool trixterxdreamv1client::ReceiveChar(char c) {
    if (this->ProcessChar(c) != Complete)
        return false;

    lastPacket.Steering = this->byteBuffer[0x1];
    lastPacket.Flywheel = (static_cast<uint16_t>(this->byteBuffer[0xC]) << 8) + this->byteBuffer[0xD];
    lastPacket.Crank = (static_cast<uint16_t>(this->byteBuffer[0xA]) << 8) + this->byteBuffer[0xB];
    lastPacket.HeartRate = byteBuffer[0xE];

    constexpr double millisecondsToBaseUnit = 1024.0 / 1000.0;
    constexpr double flywheelToRevolutionsPerMinute = 576000.0;
    constexpr double crankToRevolutionsPerMinute = 1.0 / 6e-6;
    constexpr double PI = 3.14159265358979323846;
    constexpr double revolutionsPerMinuteToRadiansPerSecond = PI / 30;

    double flywheelAngularVelocity = 0, crankAngularVelocity = 0;

    if (lastPacket.Flywheel < 65534) {
        flywheelAngularVelocity =
            flywheelToRevolutionsPerMinute * revolutionsPerMinuteToRadiansPerSecond / std::max(static_cast<uint16_t>(1), lastPacket.Flywheel);
    }

    if (lastPacket.Crank > 0 && lastPacket.Crank < 65534) {
        crankAngularVelocity =
            crankToRevolutionsPerMinute * revolutionsPerMinuteToRadiansPerSecond / std::max(static_cast<uint16_t>(1), lastPacket.Crank);
    }

    const uint32_t t = this->get_time_ms();
    const uint32_t dt = t - this->lastT;

    if (dt <= 0) {
        // TODO: error logging - this could be indicative of a problem
        // It should usually be about 12ms
        this->Reset();
        return false;
    }

    // update the internal, precise state
    this->lastT = t;
    this->flywheelRevolutions += dt * flywheelAngularVelocity / (2 * PI);
    this->crankRevolutions += dt * crankAngularVelocity / (2 * PI);

    state newState{};

    newState.LastEventTime = static_cast<uint16_t>(millisecondsToBaseUnit * t);
    newState.Steering = lastPacket.Steering;
    newState.HeartRate = lastPacket.HeartRate;
    newState.CumulativeCrankRevolutions = static_cast<uint16_t>(round(flywheelRevolutions));
    newState.CumulativeWheelRevolutions = static_cast<uint32_t>(round(crankRevolutions));

    // TODO: get a mutex lock to make this change so it doesn't interfere with getLastState()
    this->lastState = newState;

    return true;
}

trixterxdreamv1client::state trixterxdreamv1client::getLastState() const {
    // TODO: get a mutex lock to read this so it doesn't interfere with ReceiveChar
    return this->lastState;
}

void trixterxdreamv1client::SendResistance(int level) {

    // to maintain the resistance, this needs to be resent about every 10ms.
    if(level!=0 && this->write_bytes)
    {
        // TODO: send this every 50ms. This single call won't do anything noticable
        this->write_bytes(this->resistanceMessages[std::max(250, std::min(0, level))],6);
    }
}



void trixterxdreamv1client::Reset() {
    this->lastT = this->get_time_ms();
    this->flywheelRevolutions = 0.0;
    this->crankRevolutions = 0.0;
}
