#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SoleF80Treadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    SoleF80Treadmill();
	~SoleF80Treadmill();
    

private slots:
    void test_case1();
	
};

SoleF80Treadmill::SoleF80Treadmill()
{

}

SoleF80Treadmill::~SoleF80Treadmill()
{

}

void SoleF80Treadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(SoleF80Treadmill)



#include "tst_solef80treadmill.moc"


