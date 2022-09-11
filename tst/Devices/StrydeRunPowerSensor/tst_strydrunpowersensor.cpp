#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class StrydeRunPowerSensor : public BluetoothDevice
{
    Q_OBJECT

public:
    StrydeRunPowerSensor();
	~StrydeRunPowerSensor();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

StrydeRunPowerSensor::StrydeRunPowerSensor()
{

}

StrydeRunPowerSensor::~StrydeRunPowerSensor()
{

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


