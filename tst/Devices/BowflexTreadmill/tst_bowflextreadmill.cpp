#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class BowflexTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    BowflexTreadmill();
	~BowflexTreadmill();
    

private slots:
    void test_case1();
	
};

BowflexTreadmill::BowflexTreadmill()
{

}

BowflexTreadmill::~BowflexTreadmill()
{

}

void BowflexTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(BowflexTreadmill)


#include "tst_bowflextreadmill.moc"



