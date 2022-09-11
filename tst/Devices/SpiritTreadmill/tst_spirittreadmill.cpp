#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SpiritTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    SpiritTreadmill();
	~SpiritTreadmill();
    

private slots:
    void test_case1();
	
};

SpiritTreadmill::SpiritTreadmill()
{

}

SpiritTreadmill::~SpiritTreadmill()
{

}

void SpiritTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(SpiritTreadmill)



#include "tst_spirittreadmill.moc"


