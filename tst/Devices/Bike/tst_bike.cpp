#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "bike.h"

class Bike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(Bike)

	Bike();
	~Bike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

Bike::Bike()
{

}

Bike::~Bike()
{

}

bool Bike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<bike*>(detectedDevice)!=nullptr;	
}

QStringList Bike::get_deviceNames() {
	QStringList result;
	return result;
 }

void Bike::test_case1()
{

}

DECLARE_TEST(Bike)



#include "tst_bike.moc"


