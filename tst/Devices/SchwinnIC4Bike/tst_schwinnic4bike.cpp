#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "schwinnic4bike.h"

class SchwinnIC4Bike : public BluetoothDevice
{
	Q_OBJECT

public:
	SchwinnIC4Bike();
	~SchwinnIC4Bike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SchwinnIC4Bike::SchwinnIC4Bike()
{

}

SchwinnIC4Bike::~SchwinnIC4Bike()
{

}

bool SchwinnIC4Bike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<schwinnic4bike*>(detectedDevice)!=nullptr;	
}

QStringList SchwinnIC4Bike::get_deviceNames() {
	QStringList result;
	return result;
 }

void SchwinnIC4Bike::test_case1()
{

}

DECLARE_TEST(SchwinnIC4Bike)



#include "tst_schwinnic4bike.moc"


