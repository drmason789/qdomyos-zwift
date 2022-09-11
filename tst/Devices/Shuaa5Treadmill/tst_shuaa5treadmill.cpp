#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Shuaa5Treadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    Shuaa5Treadmill();
	~Shuaa5Treadmill();
    

private slots:
    void test_case1();
	
};

Shuaa5Treadmill::Shuaa5Treadmill()
{

}

Shuaa5Treadmill::~Shuaa5Treadmill()
{

}

void Shuaa5Treadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(Shuaa5Treadmill)



#include "tst_shuaa5treadmill.moc"


