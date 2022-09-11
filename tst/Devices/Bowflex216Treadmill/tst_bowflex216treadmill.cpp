#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Bowflex216Treadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    Bowflex216Treadmill();
	~Bowflex216Treadmill();
    

private slots:
    void test_case1();
	
};

Bowflex216Treadmill::Bowflex216Treadmill()
{

}

Bowflex216Treadmill::~Bowflex216Treadmill()
{

}

void Bowflex216Treadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(Bowflex216Treadmill)

#include "tst_bowflex216treadmill.moc"
