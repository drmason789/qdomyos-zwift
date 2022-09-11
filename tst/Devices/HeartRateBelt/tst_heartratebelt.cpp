#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class HeartRateBelt : public BluetoothDevice
{
    Q_OBJECT

public:
    HeartRateBelt();
	~HeartRateBelt();
    

private slots:
    void test_case1();
	
};

HeartRateBelt::HeartRateBelt()
{

}

HeartRateBelt::~HeartRateBelt()
{

}

void HeartRateBelt::test_case1()
{

}

QTEST_APPLESS_MAIN(HeartRateBelt)



#include "tst_heartratebelt.moc"


