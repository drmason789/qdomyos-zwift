#pragma once

#include <vector>
#include <unordered_set>

#include <QString>
#include <QBluetoothDeviceInfo>

#include "bluetoothdevice.h"
#include "devicenamepatterngroup.h"
#include "devicediscoveryinfo.h"

typedef std::function<void(const DeviceDiscoveryInfo &info, bool enable, std::vector<DeviceDiscoveryInfo> &configurations)> ConfigurationApplicatorMultiple;
typedef std::function<void(DeviceDiscoveryInfo &info, bool enable)> ConfigurationApplicatorSingle;
typedef std::function<void()> ExclusionCollector;
typedef std::function<void(const QBluetoothDeviceInfo &info, bool enable, std::vector<QBluetoothDeviceInfo> &bluetoothDeviceInfos)> BluetoothInfoApplicatorMultiple;
typedef std::function<void(QBluetoothDeviceInfo &info, const QBluetoothUuid& uuid, bool enable)> BluetoothInfoApplicatorSingle;


class ProductTestData
{
protected:
    bool enabled = true;
    bool skipped = false;
    QString disabledReason = nullptr;
    QString skippedReason = nullptr;
    QString name = nullptr;
    std::unordered_set<int> exclusions;
    DeviceNamePatternGroup * deviceNamePatternGroup=nullptr;
    ConfigurationApplicatorMultiple configuratorMultiple=nullptr;
    ConfigurationApplicatorSingle configuratorSingle=nullptr;
    BluetoothInfoApplicatorMultiple bluetoothInfosConfigurator=nullptr;
    BluetoothInfoApplicatorSingle bluetoothInfoConfigurator=nullptr;
    std::function<bool(bluetoothdevice*)> isExpectedDevice=nullptr;
    int expectedDeviceType = -1;
    ProductTestData();
public:
    QString Name() const;
    int ExpectedDeviceType() const;
    bool IsEnabled() const;
    bool IsSkipped() const { return skipped; }
    const QString DisabledReason() const;
    const QString SkippedReason() const;
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
