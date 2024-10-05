#pragma once


#include "bluetoothdevice.h"
#include "producttestdata.h"

class ProductTestDataBuilder : public virtual ProductTestData
{

public:
    ProductTestDataBuilder(QString name);

    template <typename T>
    ProductTestDataBuilder * expectDevice()
    {
        if(this->isExpectedDevice)
            throw std::invalid_argument("Expected device already set.");

        this->isExpectedDevice= [](bluetoothdevice * detectedDevice) -> bool { return dynamic_cast<T*>(detectedDevice)!=nullptr; };

        return this;
    }

    /**
     * @brief Add a device name that should be identified as this device.
     * If the comparison specified contains "starts with", then samples that start with the
     * specified device name will be added. If a case sensitive comparison is specified,
     * samples with invalid casing will be added to the invalid names list.
     * @param deviceName
     * @param length The expected length. Use 0 for unrestricted.
     */
    ProductTestDataBuilder * acceptDeviceName(const QString& deviceName, DeviceNameComparison cmp, uint8_t length=0);

    /**
     * @brief Add a device name as a prefix and suffix that should be identified as this device.
     * If a case sensitive comparison is specified,
     * samples with invalid casing will be added to the invalid names list.
     * @param deviceName
     */
    ProductTestDataBuilder * acceptDeviceName(const QString& deviceNameStartsWith, const QString& deviceNameEndsWith, DeviceNameComparison cmp);

    /**
     * @brief Add a device name that should NOT be identified as this device.
     * @param deviceName
     */
    ProductTestDataBuilder * rejectDeviceName(const QString& deviceName, const DeviceNameComparison cmp);

    ProductTestDataBuilder * configureSettingsWith(DeviceDiscoveryInfosCollector configurator);

    ProductTestDataBuilder * configureSettingsWith(DeviceDiscoveryInfoCollector configurator);

    ProductTestDataBuilder * configureSettingsWith(const QString& qzSettingsKey);

    ProductTestDataBuilder * configureBluetoothInfoWith(const BluetoothDeviceInfoCollector& configurator);

    ProductTestDataBuilder * excluding(const QString& exclusion);

    ProductTestDataBuilder * excluding(const QStringList& exclusions);

    ProductTestDataBuilder * excluding(std::initializer_list<QString> exclusions);

    ProductTestDataBuilder * disable();

};
