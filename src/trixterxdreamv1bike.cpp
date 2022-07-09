#include "trixterxdreamv1bike.h"


trixterxdreamv1bike::trixterxdreamv1bike(bool noWriteResistance, bool noHeartService, bool noVirtualDevice)
{
    auto x = this;
    this->port.set_bytes_read([&x](QByteArray bytes) -> void {x->update(bytes); });

}

void trixterxdreamv1bike::update(QByteArray bytes)
{
    char c; // let this be the new byte from the serial port, expected to be '0'..'9' or 'a'..'f'
    bool stateChanged = false;

    for(int i=0; i<bytes.length();i++)
    {
        unsigned long t = 0; // TODO: get the milliseconds (not the BT unit of 1/1024ms) since t0
        stateChanged = this->client.ReceiveChar(c, t);
    }

    if(!stateChanged)
        return;

    // Take the most recent state read
    auto state = this->client.getLastState();

    // presumeably the values can be copied from the state object to members of the base class
    // TODO: find out what to do with the incoming values
    bike::Heart.setValue(state.HeartRate);
    bike::steeringAngleChanged(90.0 / 250.0 * state.Steering -45.0);
    this->LastCrankEventTime = state.LastCrankEventTime;

    // TODO: what to do with these?
    //state.CumulativeCrankRevolutions;
    //state.CumulativeWheelRevolutions;
    //state.LastWheelEventTime;

}


trixterxdreamv1bike::~trixterxdreamv1bike()
{
    this->port.quit();
}
