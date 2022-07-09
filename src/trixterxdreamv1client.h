#pragma once
#include <queue>
#include <vector>
#include <stdint.h>
#include <bits/std_function.h>

class trixterxdreamv1client {
  public:
    /**
     * \brief Device state data: CSCS, heartrate and steering.
     */
    struct state {
        /**
         * \brief Steering value, from 0 (left) to 250 (right)
         */
        uint8_t Steering;

        /**
         * \brief Heart rate in beats per minute.
         */
        uint8_t HeartRate;

        /**
         * \brief The number of flywheel revolutions since the last reset event.
         */
        uint16_t CumulativeWheelRevolutions;

        /**
         * \brief The time of the last flywheel event. Unit:  1/1024 s
         */
        uint16_t LastWheelEventTime;

        /**
         * \brief The number of crank revolutions since the last reset event.
         */
        uint16_t CumulativeCrankRevolutions;

        /**
         * \brief  The time of the last crank event. Unit:  1/1024 s
         */
        uint16_t LastCrankEventTime;
    };

  private:
    unsigned char **resistanceMessages{};

    enum PacketState { None, Incomplete, Invalid, Complete };

    struct Packet {
        uint8_t Steering;
        uint16_t Flywheel;
        uint16_t Crank;
        uint8_t HeartRate;
    };


    std::function<void(uint8_t * , int)> write_bytes;
    unsigned long lastT = 0;
    double flywheelRevolutions{}, crankRevolutions{};
    Packet lastPacket{};
    std::vector<char> inputBuffer;
    std::vector<uint8_t> byteBuffer;
    state lastState;

    /**
     * \brief Clear the input buffer.
     */
    void ResetBuffer();

    /**
     * \brief Add the character to the input buffer and process to eventually read the next packet.
     * \param c A text character '0'..'9' or 'a'..'f'
     * \return
     */
    PacketState ProcessChar(char c);

    void ConfigureResistanceMessages();

  public:
    trixterxdreamv1client();

    /**
     * \brief Receives and processes a character of input from the device.
     * \param c Should be '0' to '9' or 'a' to 'f' (lower case)
     * \param t The time: the number of milliseconds since the last reset.
     * \return true if a packet was completed and the state updated, otherwise false.
     */
    bool ReceiveChar(char c, unsigned long t);

    /**
     * \brief set_WriteBytes Sets the function used to write bytes to the serial port.
     * \param write_byes The function that writes bytes to the serial port.
     */
    void set_WriteBytes(std::function<void(uint8_t *, int)> write_bytes) { this->write_bytes = write_bytes; }

    /**
     * \brief Gets the state of the device as it was last read. This consists of CSCS data, steering and heartbeat.
     * \return The last state.
     */
    state getLastState() const;

    /**
     * \brief Reset the Cycle Speed and Cadence information.
     */
    void Reset();

    /**
     * \brief Sends 1 packet indicating a specific resistance level to the device.
     * \param level 0 to 250.
     */
    void SendResistance(int level);
};
