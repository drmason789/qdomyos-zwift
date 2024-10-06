#include "producttestdata.h"
#include "producttestdataindex.h"

QString ProductTestData::Name() const { return this->name; }

DeviceTypeId ProductTestData::ExpectedDeviceType() const {
    if(this->expectedDeviceType<0)
        throw std::domain_error("Expected device not set");
    return this->expectedDeviceType;
}

bool ProductTestData::IsEnabled() const { return this->enabled; }


const QString ProductTestData::DisabledReason() const  { return this->disabledReason; }

const QString ProductTestData::SkippedReason() const  { return this->skippedReason; }

bool ProductTestData::IsExpectedDevice(bluetoothdevice *device) const { return this->isExpectedDevice(device); }

const QStringList ProductTestData::Exclusions() const {
    auto testData = ProductTestDataIndex::WhereExpects(this->exclusions);

    QString missing = "";

    // first check that all the product test data is there
    for(const auto key : this->exclusions) {
        if(!testData.contains(key))
            missing += QString("%1 ").arg(key);
    }

    if(missing.length()>0) {
        QString message = QString("Failed to find product test data for excluded ids: ")+missing;
        throw std::domain_error(message.toStdString());
    }

    QStringList result;
    for(const auto productTestData : testData.values())
        result.append(productTestData->Name());

    return result;
}

const DeviceNamePatternGroup *ProductTestData::NamePatternGroup() const { return this->deviceNamePatternGroup; }

ProductTestData::~ProductTestData(){

}

ProductTestData::ProductTestData() {}


std::vector<QBluetoothDeviceInfo> ProductTestData::ApplyBluetoothDeviceInfo(const QBluetoothUuid &uuid, const QString &name, bool valid) const {
    std::vector<QBluetoothDeviceInfo> result;

    QBluetoothDeviceInfo info(uuid, name, 0);

    if(this->bluetoothInfosConfigurator)
        this->bluetoothInfosConfigurator(info, valid, result);


    if(this->bluetoothInfoConfigurator) {
        info = QBluetoothDeviceInfo(uuid, name, 0);
        this->bluetoothInfoConfigurator(info, uuid, valid);
        result.push_back(info);
    }

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


