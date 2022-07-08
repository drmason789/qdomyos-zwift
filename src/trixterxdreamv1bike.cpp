#include "trixterxdreamv1bike.h"


trixterxdreamv1bike::trixterxdreamv1bike(bool noWriteResistance, bool noHeartService, bool noVirtualDevice)
{

}

void trixterxdreamv1bike::update()
{
    char c; // let this be the new byte from the serial port, expected to be '0'..'9' or 'a'..'f'
    unsigned long t; // time in milliseconds since t0

    if(!this->client.ReceiveChar(c, t))
        return;

    auto state = this->client.getLastState();

    // presumeably the values can be copied from the state object to members of the base class

    bike::Heart.setValue(state.HeartRate);



}
