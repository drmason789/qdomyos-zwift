#pragma once

#include "Devices/bluetoothdevicetestdata.h"
#include "devices/bike.h"

class BikeOptions {
public:
   double resistanceGain=1.0, resistanceOffset=0.0;
   bool noResistance=false, noHeartService = false, noVirtualDevice = false;

};

class BikeTestData : public BluetoothDeviceTestData {
protected:
    virtual bike* doCreateInstance(const BikeOptions& options) =0;

public:
    BikeTestData(std::string deviceName) : BluetoothDeviceTestData(deviceName) {}

    deviceType get_expectedDeviceType() const override {
        return deviceType::None; // abstract
    }

    bool get_isExpectedDevice(bluetoothdevice * detectedDevice) const override {
        return dynamic_cast<bike*>(detectedDevice)!=nullptr;
    }

    bike* createInstance(const BikeOptions options) { return this->doCreateInstance(options); }
};

