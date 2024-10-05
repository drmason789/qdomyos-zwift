#include "producttestdata.h"

QString ProductTestData::Name() const { return this->name; }

bool ProductTestData::IsEnabled() const { return this->enabled; }

bool ProductTestData::IsExpectedDevice(bluetoothdevice *device) const { return this->isExpectedDevice(device); }

const QStringList ProductTestData::Exclusions() const { return this->exclusions; }

const DeviceNamePatternGroup *ProductTestData::NamePatternGroup() const { return this->deviceNamePatternGroup; }

ProductTestData::~ProductTestData(){

}

ProductTestData::ProductTestData() {}


std::vector<QBluetoothDeviceInfo> ProductTestData::ApplyBluetoothDeviceInfo(const QBluetoothUuid &uuid, const QString &name, bool valid) const {
    std::vector<QBluetoothDeviceInfo> result;

    QBluetoothDeviceInfo info(uuid, name, 0);

    if(this->bluetoothInfoConfigurator)
        this->bluetoothInfoConfigurator(info, valid, result);

    // make sure there is always a valid item
    if(valid && result.empty())
        result.push_back(info);

    return result;
}

std::vector<DeviceDiscoveryInfo> ProductTestData::ApplyConfigurations(const DeviceDiscoveryInfo &info, bool enable) const {
    std::vector<DeviceDiscoveryInfo> result;

    if(this->configuratorSingle)
    {
        DeviceDiscoveryInfo newInfo(info);
        this->configuratorSingle(newInfo, enable);
        result.push_back(newInfo);
    }

    if(this->configuratorMultiple)
        this->configuratorMultiple(info, enable, result);

    return result;
}


