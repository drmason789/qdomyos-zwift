#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "flywheelbike.h"

class FlywheelBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(FlywheelBike)

	FlywheelBike();
	~FlywheelBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

FlywheelBike::FlywheelBike()
{

}

FlywheelBike::~FlywheelBike()
{

}

bool FlywheelBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<flywheelbike*>(detectedDevice)!=nullptr;	
}

QStringList FlywheelBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void FlywheelBike::test_case1()
{

}

DECLARE_TEST(FlywheelBike)



#include "tst_flywheelbike.moc"


