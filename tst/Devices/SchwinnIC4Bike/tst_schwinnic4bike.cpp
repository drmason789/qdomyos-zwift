#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SchwinnIC4Bike : public BluetoothDevice
{
    Q_OBJECT

public:
    SchwinnIC4Bike();
	~SchwinnIC4Bike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

SchwinnIC4Bike::SchwinnIC4Bike()
{

}

SchwinnIC4Bike::~SchwinnIC4Bike()
{

}

QStringList SchwinnIC4Bike::get_deviceNames() {
	QStringList result;
	return result;
 }

void SchwinnIC4Bike::test_case1()
{

}

QTEST_APPLESS_MAIN(SchwinnIC4Bike)



#include "tst_schwinnic4bike.moc"


