#pragma once


#include <QString>
#include <QBluetoothDeviceInfo>

#include "bluetoothdevice.h"
#include "devicenamepatterngroup.h"
#include "devicediscoveryinfo.h"

typedef std::function<void(const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations)> DeviceDiscoveryInfosCollector;
typedef std::function<void(DeviceDiscoveryInfo &info, bool enable)> DeviceDiscoveryInfoCollector;
typedef std::function<void()> ExclusionCollector;
typedef std::function<void(const QBluetoothDeviceInfo &info, bool enable, std::vector<QBluetoothDeviceInfo> &bluetoothDeviceInfos)> BluetoothDeviceInfoCollector;


class ProductTestData
{
protected:
    bool enabled = true;
    QString name = nullptr;
    QStringList exclusions;
    DeviceNamePatternGroup * deviceNamePatternGroup=nullptr;
    DeviceDiscoveryInfosCollector configuratorMultiple=nullptr;
    DeviceDiscoveryInfoCollector configuratorSingle=nullptr;
    BluetoothDeviceInfoCollector bluetoothInfoConfigurator=nullptr;
    std::function<bool(bluetoothdevice*)> isExpectedDevice=nullptr;
    ProductTestData();
public:
    QString Name() const;
    bool IsEnabled() const;
    bool IsExpectedDevice(bluetoothdevice * device) const;
    const QStringList Exclusions() const;
    const DeviceNamePatternGroup * NamePatternGroup() const;

    /**
     * @brief Gets combinations of configurations beginning with the specified object.
     * @param info
     */
    std::vector<DeviceDiscoveryInfo> ApplyConfigurations(const DeviceDiscoveryInfo& info, bool enable) const;

    /**
     * @brief Gets a vector of QBluetoothDeviceInfo objects for the specified name and UUID. Can be used to
     * generate valid and invalid objects where device identification relies on more than just the name.
     * @param uuid
     * @param name
     * @param valid
     */
    std::vector<QBluetoothDeviceInfo> ApplyBluetoothDeviceInfo(const QBluetoothUuid& uuid, const QString& name, bool valid=true) const;

    virtual ~ProductTestData();
};
