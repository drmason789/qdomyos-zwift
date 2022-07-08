#pragma once
#include "bike.h"
#include "trixterxdreamv1client.h"

class trixterxdreamv1bike : public bike
{
    Q_OBJECT
private:
    trixterxdreamv1client client;

    
    /**
     * \brief Temporary method to contain what happens when a new character comes in
     * from the serial port.
     */
    void update();
public:

    trixterxdreamv1bike(bool noWriteResistance, bool noHeartService, bool noVirtualDevice);

};
