#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "strydrunpowersensor.h"

class StrydeRunPowerSensor : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(StrydeRunPowerSensor)

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
    return dynamic_cast<strydrunpowersensor*>(detectedDevice)!=nullptr;
}

QStringList StrydeRunPowerSensor::get_deviceNames() {
	QStringList result;
	return result;
 }

void StrydeRunPowerSensor::test_case1()
{

}

DECLARE_TEST(StrydeRunPowerSensor)



#include "tst_strydrunpowersensor.moc"


