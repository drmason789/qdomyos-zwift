#pragma once


#include "bluetoothdevice.h"
#include "producttestdata.h"
#include "producttestdataindex.h"

/**
 * @brief Extra functionality on a ProductTestData for configuring it.
 */
class ProductTestDataBuilder : public virtual ProductTestData
{

public:
    ProductTestDataBuilder(QString name);

    /**
     * @brief Indicates the type of bluetoothdevice object that should be produced from the conditions defined in this object.
     * @return
     */
    template <class T>
    ProductTestDataBuilder * expectDevice()
    {
        if(this->isExpectedDevice)
            throw std::invalid_argument("Expected device already set.");

        this->isExpectedDevice= [](bluetoothdevice * detectedDevice) -> bool { return dynamic_cast<T*>(detectedDevice)!=nullptr; };
        this->expectedDeviceType = ProductTestDataIndex::GetTypeId<T>();

        // TODO enhance exclusion test to be able to distinguish instances rather than just type.
        // // Exclude this type, i.e. don't redetect and recreate.
        // this->excluding<T>();

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

    /**
     * @brief Specifies that a single setting is used to generate an enabling or disabling configuration,
     * and additionally specify the enabling value and disabling value, which must be different.
     * @param qzSettingsKey The settings key to alter.
     * @param enablingValue The value of the setting that indicates an enabling configuration.
     * @param disablingValue The value of the setting that indicates a disabling configuration.
     * @return
     */
    ProductTestDataBuilder * configureSettingsWith(const QString &qzSettingsKey, QVariant enablingValue, QVariant disablingValue);

    /**
     * @brief Specifies that a single bluetooth service is used to generate an enabling or disabling configuration.
     * @param uuid The UUID of the bluetooth service.
     * @param addedIsEnabled Indicates what the presence of the service indicates.
     * @return
     */
    ProductTestDataBuilder * configureSettingsWith(const QBluetoothUuid &uuid, bool addedIsEnabled=true);

    /**
     * @brief Indicates that if a device of the types with the specified type ids is already recognised,
     * this one should not be detected even if the other conditions are met.
     * @param exclusions
     * @return
     */
    ProductTestDataBuilder * excluding(std::initializer_list<DeviceTypeId> exclusions);

    /**
     * @brief Indicates that if a device of the specified type is already recognised,
     * this one should not be detected even if the other conditions are met.
     * @return
     */
    template<class T>
    ProductTestDataBuilder * excluding() { return excluding({ProductTestDataIndex::GetTypeId<T>()}); }

    /**
     * @brief Disable the test data, optionally stating a reason, and excluding it from any test reports.
     * @param reason
     * @return
     */
    ProductTestDataBuilder * disable(const QString& reason=nullptr);

    /**
     * @brief Indicates that the test data should be included in tests, but skipped so it appears in reports as having been skipped,
     * with an optional reason.
     * @param reason
     * @return
     */
    ProductTestDataBuilder * skip(const QString& reason=nullptr);
};
