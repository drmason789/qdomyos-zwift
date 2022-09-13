#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "stryderunpowersensor.h"

class StrydeRunPowerSensor : public BluetoothDevice
{
	Q_OBJECT

public:
	StrydeRunPowerSensor();
	~StrydeRunPowerSensor();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

StrydeRunPowerSensor::StrydeRunPowerSensor()
{

}

StrydeRunPowerSensor::~StrydeRunPowerSensor()
{

}

bool StrydeRunPowerSensor::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<stryderunpowersensor*>(detectedDevice)!=nullptr;	
}

QStringList StrydeRunPowerSensor::get_deviceNames() {
	QStringList result;
	return result;
 }

void StrydeRunPowerSensor::test_case1()
{

}

QTEST_APPLESS_MAIN(StrydeRunPowerSensor)



#include "tst_strydrunpowersensor.moc"


