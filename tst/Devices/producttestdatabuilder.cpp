#include "producttestdatabuilder.h"

ProductTestDataBuilder::ProductTestDataBuilder(QString name) : ProductTestData() {
    this->name = name;
    this->deviceNamePatternGroup = new DeviceNamePatternGroup();
}

ProductTestDataBuilder *ProductTestDataBuilder::acceptDeviceNames(const QStringList &deviceNames, DeviceNameComparison cmp)
{
    for(QString name : deviceNames)
        this->acceptDeviceName(name, cmp);
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::acceptDeviceName(const QString &deviceName, DeviceNameComparison cmp, uint8_t length) {
    this->deviceNamePatternGroup->addDeviceName(deviceName, cmp, length);
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::acceptDeviceName(const QString &deviceNameStartsWith, const QString &deviceNameEndsWith, DeviceNameComparison cmp) {
    this->deviceNamePatternGroup->addDeviceName(deviceNameStartsWith, deviceNameEndsWith, cmp);
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::rejectDeviceName(const QString &deviceName, const DeviceNameComparison cmp) {
    this->deviceNamePatternGroup->addInvalidDeviceName(deviceName, cmp);
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::configureSettingsWith(ConfigurationApplicatorMultiple configurator) {
    if(this->configuratorMultiple || this->configuratorSingle)
        throw std::invalid_argument("Only 1 configurator is supported.");
    this->configuratorMultiple = configurator;
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::configureSettingsWith(ConfigurationApplicatorSingle configurator) {
    if(this->configuratorMultiple || this->configuratorSingle)
        throw std::invalid_argument("Only 1 configurator is supported.");
    this->configuratorSingle = configurator;
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::configureSettingsWith(const QString &qzSettingsKey, bool enablingValue) {
    return this->configureSettingsWith(qzSettingsKey, enablingValue, !enablingValue);
}

ProductTestDataBuilder *ProductTestDataBuilder::configureSettingsWith(const QString &qzSettingsKey, QVariant enablingValue, QVariant disablingValue) {
    if(this->configuratorMultiple || this->configuratorSingle)
        throw std::invalid_argument("Only 1 configurator is supported.");

    if(enablingValue==disablingValue)
        throw std::invalid_argument("Enabling and disabling values must be different.");

    this->configuratorSingle = [qzSettingsKey, enablingValue, disablingValue](DeviceDiscoveryInfo& info, bool enable) -> void {
        info.setValue(qzSettingsKey, enable ? enablingValue:disablingValue);
    };
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::configureSettingsWith(const QBluetoothUuid &uuid, bool addedIsEnabled) {
    this->configuratorSingle = [uuid,addedIsEnabled](DeviceDiscoveryInfo& info, bool enable) -> void {
        if(enable==addedIsEnabled)
            info.addBluetoothService(uuid);
        else
            info.removeBluetoothService(uuid);
    };
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::excluding(std::initializer_list<DeviceTypeId> exclusions) {
    this->exclusions.insert(exclusions);
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::disable(const QString& reason) {
    this->enabled = false;
    this->disabledReason = reason;
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::skip(const QString &reason) {
    this->skipped = true;
    this->skippedReason = reason;
    return this;
}


