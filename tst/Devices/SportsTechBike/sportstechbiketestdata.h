﻿#pragma once


#include "Devices/Bike/biketestdata.h"

#include "devices/sportstechbike/sportstechbike.h"


class SportsTechBikeTestData : public BikeTestData {

public:
    SportsTechBikeTestData() : BikeTestData("Sport Tech Bike") {
        this->addDeviceName("EW-BK", comparison::StartsWithIgnoreCase);
    }

    deviceType get_expectedDeviceType() const override { return deviceType::SportsTechBike; }

    bool get_isExpectedDevice(bluetoothdevice * detectedDevice) const override {
        return dynamic_cast<sportstechbike*>(detectedDevice)!=nullptr;
    }
};

