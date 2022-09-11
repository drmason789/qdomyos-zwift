#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Bike : public BluetoothDevice
{
    Q_OBJECT

public:
    Bike();
	~Bike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

Bike::Bike()
{

}

Bike::~Bike()
{

}

QStringList Bike::get_deviceNames() {
	QStringList result;
	return result;
 }

void Bike::test_case1()
{

}

QTEST_APPLESS_MAIN(Bike)



#include "tst_bike.moc"


