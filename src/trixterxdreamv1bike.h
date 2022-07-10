#pragma once
#include "bike.h"
#include "trixterxdreamv1client.h"
#include "trixterxdreamv1serial.h"

class trixterxdreamv1bike : public bike
{
    Q_OBJECT
private:
    /**
     * \brief client An object that processes incoming data to CSCS, heart rate and steering data
     */
    trixterxdreamv1client client;

    /**
     * \brief port An object that monitors a serial port to read incoming data, and to write
     * resistance level requests.
     */
    trixterxdreamv1serial port;

    /**
     * \brief noHeartService Suppress heart rate readings.
     */
    bool noHeartService;

    /**
     * \brief noVirtualDevice Suppress virtual device.
     */
    bool noVirtualDevice;

    /**
     * \brief noWriteResistance Suppress sending resistance to device.
     */
    bool noWriteResistance;

    /**
     * \brief t0 The start time in milliseconds. Used to reduce te size of time values processed.
     */
    qint64 t0;

    /**
     * \brief getTime Gets the time in miliseconds since this object was created.
     * \return The number of milliseconds since this object was created.
     */
    uint32_t getTime();
    
    /**
     * \brief Temporary method to contain what happens when a new block of data comes in
     * from the data source (serial port).
     */
    void update(QByteArray bytes);
public:

    trixterxdreamv1bike(bool noWriteResistance, bool noHeartService, bool noVirtualDevice);

    ~trixterxdreamv1bike();

    /**
     * @brief maxResistance The maximum resistance supported.
     * @return
     */
    virtual uint8_t maxResistance() { return trixterxdreamv1client::MaxResistance; }
};
