#include "trixterxdreamv1bike.h"


trixterxdreamv1bike::trixterxdreamv1bike(bool noWriteResistance, bool noHeartService, bool noVirtualDevice)
{
    // QZ things from expected constructor
    this->noWriteResistance = noWriteResistance;
    this->noHeartService = noHeartService;
    this->noVirtualDevice = noVirtualDevice;

    // Get the current time in milliseconds since ancient times.
    // This will be subtracted from further readings from getTime() to get an easier to look at number.
    this->t0 = QDateTime::currentDateTime().toMSecsSinceEpoch();

    // References to objects for callbacks
    auto thisObject = this;
    auto device=&this->port;

    // tell the client where to get the time
    this->client.set_GetTime([&thisObject]()->uint32_t { return thisObject->getTime();} );

    // tell the client how to send data to the device
    if(!noWriteResistance)
        this->client.set_WriteBytes([device](uint8_t * bytes, int length)->void{ device->write(bytes, length, "");});

    // tell the serial port where to send incoming data blocks
    this->port.set_bytes_read([&thisObject](QByteArray bytes) -> void {thisObject->update(bytes); });

    // open the port. This should be at 115200 bits per second.
    // TODO: determine if this is the right port, and add the ability to specify the port name.
    this->port.open("/dev/ttyUSB0", 10000);


}

uint32_t trixterxdreamv1bike::getTime()
{
    return static_cast<uint32_t>(QDateTime::currentDateTime().toMSecsSinceEpoch() - this->t0);
}

void trixterxdreamv1bike::update(QByteArray bytes)
{
    bool stateChanged = false;

    for(int i=0; i<bytes.length();i++)
        stateChanged |= this->client.ReceiveChar(bytes[i]);

    if(!stateChanged)
        return;

    // Take the most recent state read
    auto state = this->client.getLastState();

    // update the metrics
    if(!this->noHeartService)
        this->Heart.setValue(state.HeartRate);
    this->LastCrankEventTime = state.LastEventTime;

    this->CrankRevs = state.CumulativeCrankRevolutions; // TODO: probablu needs to be assigned to Cadence instead, but what are the units?
    this->Speed.setValue(state.CumulativeWheelRevolutions); // TODO: this is wrong, fix it.
    this->currentSteeringAngle().setValue(90.0 / 250.0 * state.Steering -45.0);

}

trixterxdreamv1bike::~trixterxdreamv1bike()
{
    this->port.quit();
}
