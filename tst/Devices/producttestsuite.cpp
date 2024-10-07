#include "producttestsuite.h"
#include "discoveryoptions.h"
#include "bluetooth.h"
#include "bluetoothsignalreceiver.h"
#include "producttestdataindex.h"

const QString testUUID = QStringLiteral("b8f79bac-32e5-11ed-a261-0242ac120002");
QBluetoothUuid uuid{testUUID};


void ProductTestSuite::tryDetectDevice(bluetooth &bt,
                                                  const QBluetoothDeviceInfo &deviceInfo) const {
    try {
        // It is possible to use an EXPECT_NO_THROW here, but this
        // way is easier to place a breakpoint on the call to bt.deviceDiscovered.
        bt.homeformLoaded = true;
        bt.deviceDiscovered(deviceInfo);
    } catch (...) {
        FAIL() << "Failed to perform device detection.";
    }
}

std::string ProductTestSuite::getTypeName(bluetoothdevice *b) const {
    if(!b) return "nullptr";
    QString name = typeid(*b).name();

    int length = name.length();
    int sum = 0, i=0;
    while(i<length && name[i].isDigit() && sum!=length-i) {
        sum = sum * 10 + name[i].toLatin1()-(char)'0';
        i++;
    }

    if(sum==length-i)
        return name.right(length-i).toStdString();

    return name.toStdString();
}


std::string ProductTestSuite::formatString(std::string format, bluetoothdevice *b) const {

    QString qs = QString(format.c_str());
    QString typeName = this->getTypeName(b).c_str();
    return qs.replace("{typeName}", typeName).toStdString();
}

void ProductTestSuite::testDeviceDetection(const ProductTestData * testData, bluetooth &bt,
                                                      const QBluetoothDeviceInfo &deviceInfo,
                                                  bool expectMatch,
                                                  bool restart,
                                                  const QString& failMessage) const {
    this->testDeviceDetection(testData, bt, deviceInfo, expectMatch, restart, failMessage.toStdString());
}



void ProductTestSuite::testDeviceDetection(const ProductTestData * testData, bluetooth &bt,
                                                  const QBluetoothDeviceInfo &deviceInfo,
                                                  bool expectMatch,
                                                  bool restart,
                                                  const std::string& failMessage) const {

    BluetoothSignalReceiver signalReceiver(bt);


    this->tryDetectDevice(bt, deviceInfo);

    bluetoothdevice * device = bt.device();

    if(expectMatch) {
        std::string formattedFailMessage = this->formatString(failMessage, device);
        EXPECT_NE(device, nullptr) << formattedFailMessage;
        EXPECT_TRUE(testData->IsExpectedDevice(device)) << formattedFailMessage;

        EXPECT_EQ(device, signalReceiver.get_device()) << "Connection signal not received";
    } else {
        EXPECT_FALSE(testData->IsExpectedDevice(device)) << this->formatString(failMessage, device);
    }

    if(restart) {
        bt.restart();
        EXPECT_EQ(nullptr, signalReceiver.get_device()) << "Disconnection signal not received";
    }
}

void ProductTestSuite::SetUp() {
    auto testParam = this->GetParam();

    this->testParam = ProductTestDataIndex::GetProductTestData(testParam);

    if(!this->testParam)
        GTEST_FAIL() << "Failed to get test data for: " << testParam.toStdString();

    QString skipMessage = nullptr;
    if(!this->testParam->IsEnabled())
    {
        QString reason = this->testParam->DisabledReason();
        skipMessage = QString("Product %1 is disabled for testing.").arg(testParam);

        if(reason!=nullptr && reason!="")
            skipMessage = QString("%1 Reason: %2").arg(skipMessage).arg(reason);
    }
    else if(this->testParam->IsSkipped())
    {
        QString reason = this->testParam->SkippedReason();
        skipMessage = QString("Product %1 is skipped for testing.").arg(testParam);

        if(reason!=nullptr && reason!="")
            skipMessage = QString("%1 Reason: %2").arg(skipMessage).arg(reason);
    }

    if(skipMessage!=nullptr)
        GTEST_SKIP() << skipMessage.toStdString();

    DeviceDiscoveryInfo defaultDiscoveryInfo(true);
    this->enablingConfigurations = this->testParam->ApplyConfigurations(defaultDiscoveryInfo, true);
    this->disablingConfigurations = this->testParam->ApplyConfigurations(defaultDiscoveryInfo, false);

    // Assuming these settings don't matter for this device.
    if(enablingConfigurations.size()==0)
        enablingConfigurations.push_back(defaultDiscoveryInfo);

    this->defaultDiscoveryOptions = discoveryoptions{};
    this->defaultDiscoveryOptions.startDiscovery = false;

    this->names = this->testParam->NamePatternGroup()->get_deviceNames();

    EXPECT_GT(this->names.size(), 0) << "No bluetooth names configured for test";

    this->testSettings.activate();
}


void ProductTestSuite::test_deviceDetection_validNames_enabled() {
    auto testData = this->testParam;

    bluetooth bt(this->defaultDiscoveryOptions);

    for(DeviceDiscoveryInfo discoveryInfo : enablingConfigurations) {
        for(QString deviceName : this->names)
        {
            this->testSettings.loadFrom(discoveryInfo);

            auto enablingBluetoothDeviceInfo = testData->ApplyBluetoothDeviceInfo(uuid, deviceName);
            for(size_t i=0; i<enablingBluetoothDeviceInfo.size();i++) {
                const QBluetoothDeviceInfo& deviceInfo = enablingBluetoothDeviceInfo[i];

                QString failMessage = QString("Failed to detect device for %1 using name: %2 and valid bluetooth device info: %3, got a {typeName} instead")
                                          .arg(testData->Name()).arg(deviceName).arg(i);
                this->testDeviceDetection(testData, bt, deviceInfo, true, true, failMessage);
            }
        }
    }
}

void ProductTestSuite::test_deviceDetection_validNames_disabled() {
    auto testData = this->testParam;

    bluetooth bt(this->defaultDiscoveryOptions);



        if(this->disablingConfigurations.size()==0)
            GTEST_SKIP() << "Device has no disabling configurations: " << testData->Name().toStdString();

        // Test that the device is not identified when disabled in the settings
        for(DeviceDiscoveryInfo discoveryInfo : this->disablingConfigurations) {
            for(QString deviceName : this->names)
            {
                this->testSettings.loadFrom(discoveryInfo);

                auto enablingBluetoothDeviceInfo = testData->ApplyBluetoothDeviceInfo(uuid, deviceName);
                for(size_t i=0; i<enablingBluetoothDeviceInfo.size();i++) {
                    const QBluetoothDeviceInfo& deviceInfo = enablingBluetoothDeviceInfo[i];


                    QString failMessage = QString("Created the device %1 with valid bluetooth device info config %3 when expected not to: %2")
                                                  .arg(testData->Name()).arg(deviceName).arg(i);

                    // try to create the device
                    this->testDeviceDetection(testData, bt, deviceInfo, false, true, failMessage);
                }
            }

    }
}


void ProductTestSuite::test_deviceDetection_validNames_invalidBluetoothDeviceInfo()  {
    auto testData = this->testParam;

    bluetooth bt(this->defaultDiscoveryOptions);
    bool hasInvalidBluetoothDeviceInfo = false;

    auto invalidBluetoothDeviceInfos = testData->ApplyBluetoothDeviceInfo(uuid, "fred", false);

    if(!invalidBluetoothDeviceInfos.empty()) {
        hasInvalidBluetoothDeviceInfo = true;

        std::vector<DeviceDiscoveryInfo> allConfigurations;
        for(DeviceDiscoveryInfo discoveryInfo : this->disablingConfigurations)
            allConfigurations.push_back(discoveryInfo);
        for(DeviceDiscoveryInfo discoveryInfo : this->enablingConfigurations)
            allConfigurations.push_back(discoveryInfo);

        // Test that the device is not identified when there is an invalid bluetooth device info
        for(DeviceDiscoveryInfo discoveryInfo : allConfigurations) {
            for(QString deviceName : this->names)
            {
                this->testSettings.loadFrom(discoveryInfo);

                for(const QBluetoothDeviceInfo& deviceInfo : testData->ApplyBluetoothDeviceInfo(uuid, deviceName, false)) {

                    QString failMessage = QString("Created the device %1 when bluetooth device info is invalid: %2")
                            .arg(testData->Name()).arg(deviceName);

                    // try to create the device
                    this->testDeviceDetection(testData, bt, deviceInfo, false, true, failMessage);
                }
            }
        }
    }

    if(!hasInvalidBluetoothDeviceInfo)
        GTEST_SKIP() << "Device test data has no invalid bluetooth device info defined: " << testData->Name().toStdString();
}

void ProductTestSuite::test_deviceDetection_exclusions() {
    auto testData = this->testParam;

    auto exclusionNames = testData->Exclusions();

    if(exclusionNames.size()==0)
        GTEST_SKIP() << "No exclusions defined for this device: " << testData->Name().toStdString();

    // Only take the first for each type of exclusion
    std::vector<const ProductTestData*> exclusions;
    std::unordered_set<int> exclusionTypeIds;
    for(auto exclusionName : exclusionNames)
    {
        auto productTestData = ProductTestDataIndex::GetProductTestData(exclusionName);
        if(exclusionTypeIds.count(productTestData->ExpectedDeviceType()))
            continue;
        exclusions.push_back(productTestData);
        exclusionTypeIds.insert(productTestData->ExpectedDeviceType());
    }

    bluetooth bt(this->defaultDiscoveryOptions);

    // Test that it doesn't detect this device if its higher priority "namesakes" are already detected.
    for(auto exclusion : exclusions) {
        for(DeviceDiscoveryInfo enablingDiscoveryInfo : enablingConfigurations) {
            DeviceDiscoveryInfo discoveryInfo(enablingDiscoveryInfo);

            for(QString deviceName : this->names)
            {
                // get an enabling configuration for the exclusion
                DeviceDiscoveryInfo exclusionDiscoveryInfo(true);

                QString exclusionDeviceName = exclusion->NamePatternGroup()->get_deviceNames()[0];
                QBluetoothDeviceInfo exclusionDeviceInfo = exclusion->ApplyBluetoothDeviceInfo(uuid, exclusionDeviceName)[0];
                std::vector<DeviceDiscoveryInfo> configurationsEnablingTheExclusion = exclusion->ApplyConfigurations(exclusionDiscoveryInfo, true);

                if(configurationsEnablingTheExclusion.size()>0) {
                    // get a configuration that should enable the detection of the excluding device
                    exclusionDiscoveryInfo = configurationsEnablingTheExclusion[0];
                }
                this->testSettings.loadFrom(exclusionDiscoveryInfo);

                QString failMessage = QString("Failed to create exclusion device: %1, got a {typeName} instead")
                                          .arg(exclusion->Name());
                // try to create the excluding device
                this->testDeviceDetection(exclusion, bt, exclusionDeviceInfo, true, false, failMessage);

                // now configure to have the bluetooth object try, but fail to detect the target device
                this->testSettings.loadFrom(discoveryInfo);


                auto enablingBluetoothDeviceInfo = testData->ApplyBluetoothDeviceInfo(uuid, deviceName);
                for(size_t i=0; i<enablingBluetoothDeviceInfo.size();i++) {
                    const QBluetoothDeviceInfo& deviceInfo = enablingBluetoothDeviceInfo[i];
                    failMessage = QString("Detected the %1 from %2 with valid bluetooth device info config %3 in spite of exclusion")
                                      .arg(testData->Name()).arg(deviceName).arg(i);
                    this->testDeviceDetection(testData, bt, deviceInfo, false, true, failMessage);
                }
            }

        }
    }
}

void ProductTestSuite::test_deviceDetection_invalidNames_enabled()
{
    auto testData = this->testParam;

    auto invalidNames = testData->NamePatternGroup()->get_failingDeviceNames();

    if(invalidNames.length()==0)
        GTEST_SKIP() << "No invalid names have been generated or explicitly defined for this device: " << testData->Name().toStdString();

    bluetooth bt(this->defaultDiscoveryOptions);    

    // Test that it doesn't detect this device for the "wrong" names
    for(DeviceDiscoveryInfo enablingDiscoveryInfo : enablingConfigurations) {

        DeviceDiscoveryInfo discoveryInfo(enablingDiscoveryInfo);

        for(QString deviceName : invalidNames)
        {
            this->testSettings.loadFrom(discoveryInfo);

            auto enablingBluetoothDeviceInfo = testData->ApplyBluetoothDeviceInfo(uuid, deviceName);
            for(size_t i=0; i<enablingBluetoothDeviceInfo.size();i++) {
                const QBluetoothDeviceInfo& deviceInfo = enablingBluetoothDeviceInfo[i];

                QString failMessage = QString("Detected device %1 from %2 with valid bluetooth device info config %3")
                                          .arg(testData->Name()).arg(deviceName).arg(i);

                this->testDeviceDetection(testData, bt, deviceInfo, false, true, failMessage);
            }
        }
    }
}
