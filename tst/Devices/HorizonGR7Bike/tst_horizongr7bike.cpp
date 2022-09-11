#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class HorizonGR7Bike : public BluetoothDevice
{
    Q_OBJECT

public:
    HorizonGR7Bike();
	~HorizonGR7Bike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

HorizonGR7Bike::HorizonGR7Bike()
{

}

HorizonGR7Bike::~HorizonGR7Bike()
{

}

QStringList HorizonGR7Bike::get_deviceNames() {
	QStringList result;
	return result;
 }

void HorizonGR7Bike::test_case1()
{

}

QTEST_APPLESS_MAIN(HorizonGR7Bike)



#include "tst_horizongr7bike.moc"


