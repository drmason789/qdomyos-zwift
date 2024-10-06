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
    if(this->configuratorMultiple || this->configuratorSingle)
        throw std::invalid_argument("Only 1 configurator is supported.");
    this->configuratorSingle = [qzSettingsKey, enablingValue](DeviceDiscoveryInfo& info, bool enable) -> void {
        info.setValue(qzSettingsKey, enable==enablingValue);
    };
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::configureBluetoothInfoWith(const BluetoothInfoApplicatorMultiple &configurator) {
    if(this->bluetoothInfosConfigurator || this->bluetoothInfoConfigurator)
        throw std::invalid_argument("Only 1 bluetooth information configurator is supported.");
    this->bluetoothInfosConfigurator = configurator;
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::configureBluetoothInfoWith(const BluetoothInfoApplicatorSingle &configurator) {
    if(this->bluetoothInfosConfigurator || this->bluetoothInfoConfigurator)
        throw std::invalid_argument("Only 1 bluetooth information configurator is supported.");
    this->bluetoothInfoConfigurator = configurator;
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::configureBluetoothInfoWith(const QBluetoothUuid& uuid, bool enablingValue) {

    this->bluetoothInfoConfigurator =
        [enablingValue](QBluetoothDeviceInfo &info, const QBluetoothUuid& uuid, bool enable) -> void {
            if(enable==enablingValue) {
                info.setServiceUuids(QVector<QBluetoothUuid>({uuid}));
            } else {
                info.setServiceUuids(QVector<QBluetoothUuid>({}));
            }
        };
    return this;
}
/*
ProductTestDataBuilder *ProductTestDataBuilder::excluding(const QString &exclusion) {
    this->exclusions.append(exclusion);
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::excluding(const QStringList &exclusions) {
    this->exclusions.append(exclusions);
    return this;
}

ProductTestDataBuilder *ProductTestDataBuilder::excluding(std::initializer_list<QString> exclusions) {
    this->exclusions.append(exclusions);
    return this;
}
*/
ProductTestDataBuilder *ProductTestDataBuilder::excluding(std::initializer_list<int> exclusions) {
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


