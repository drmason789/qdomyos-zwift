#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "horizongr7bike.h"

class HorizonGR7Bike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(HorizonGR7Bike)

	HorizonGR7Bike();
	~HorizonGR7Bike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

HorizonGR7Bike::HorizonGR7Bike()
{

}

HorizonGR7Bike::~HorizonGR7Bike()
{

}

bool HorizonGR7Bike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<horizongr7bike*>(detectedDevice)!=nullptr;	
}

QStringList HorizonGR7Bike::get_deviceNames() {
	QStringList result;
	return result;
 }

void HorizonGR7Bike::test_case1()
{

}

DECLARE_TEST(HorizonGR7Bike)



#include "tst_horizongr7bike.moc"


