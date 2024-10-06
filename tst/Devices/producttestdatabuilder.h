#pragma once


#include "bluetoothdevice.h"
#include "producttestdata.h"
#include "producttestdataindex.h"

class ProductTestDataBuilder : public virtual ProductTestData
{

public:
    ProductTestDataBuilder(QString name);

    template <class T>
    ProductTestDataBuilder * expectDevice()
    {
        if(this->isExpectedDevice)
            throw std::invalid_argument("Expected device already set.");

        this->isExpectedDevice= [](bluetoothdevice * detectedDevice) -> bool { return dynamic_cast<T*>(detectedDevice)!=nullptr; };
        this->expectedDeviceType = ProductTestDataIndex::GetTypeId<T>();
        return this;
    }

    /**
     * @brief Add a list of device names that should be identified as this device.
     * If the comparison specified contains "starts with", then samples that start with the
     * specified device name will be added. If a case sensitive comparison is specified,
     * samples with invalid casing will be added to the invalid names list.
     * @param deviceNames
     */
    ProductTestDataBuilder * acceptDeviceNames(const QStringList& deviceNames, DeviceNameComparison cmp);

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

    /**
     * @brief Sets a generator for multiple enabling or disabling settings configurations.
     * @param configurator
     * @return
     */
    ProductTestDataBuilder * configureSettingsWith(ConfigurationApplicatorMultiple configurator);

    /**
     * @brief Sets a functor to produce the single enabling or disabling settings configuration.
     * @param configurator
     * @return
     */
    ProductTestDataBuilder * configureSettingsWith(ConfigurationApplicatorSingle configurator);

    /**
     * @brief Specifies that a single boolean setting is used to generate an enabling or
     *  disabling configuration.
     * @param qzSettingsKey The settings key to alter.
     * @param enabledValue The value of the setting that indicates an enabling configuration.
     * @return
     */
    ProductTestDataBuilder * configureSettingsWith(const QString& qzSettingsKey, bool enabledValue=true);

    ProductTestDataBuilder * configureSettingsWith(const QString &qzSettingsKey, QVariant enablingValue, QVariant disablingValue);

    ProductTestDataBuilder * configureBluetoothInfoWith(const BluetoothInfoApplicatorMultiple& configurator);
    ProductTestDataBuilder * configureBluetoothInfoWith(const BluetoothInfoApplicatorSingle& configurator);
    ProductTestDataBuilder * configureBluetoothInfoWith(const QBluetoothUuid &uuid, bool enablingValue=true);


    //ProductTestDataBuilder * excluding(const QString& exclusion);
    //ProductTestDataBuilder * excluding(const QStringList& exclusions);
    //ProductTestDataBuilder * excluding(std::initializer_list<QString> exclusions);
    ProductTestDataBuilder * excluding(std::initializer_list<DeviceTypeId> exclusions);

    template<class T>
    ProductTestDataBuilder * excluding() { return excluding({ProductTestDataIndex::GetTypeId<T>()}); }

    ProductTestDataBuilder * disable(const QString& reason=nullptr);

    ProductTestDataBuilder * skip(const QString& reason=nullptr);



};
