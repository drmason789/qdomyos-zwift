#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Treadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    Treadmill();
	~Treadmill();
    

private slots:
    void test_case1();
	
};

Treadmill::Treadmill()
{

}

Treadmill::~Treadmill()
{

}

void Treadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(Treadmill)



#include "tst_treadmill.moc"


