#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class HorizonTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    HorizonTreadmill();
	~HorizonTreadmill();
    

private slots:
    void test_case1();
	
};

HorizonTreadmill::HorizonTreadmill()
{

}

HorizonTreadmill::~HorizonTreadmill()
{

}

void HorizonTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(HorizonTreadmill)



#include "tst_horizontreadmill.moc"


