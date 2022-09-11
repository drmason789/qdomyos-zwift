#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FTMSRower : public BluetoothDevice
{
    Q_OBJECT

public:
    FTMSRower();
	~FTMSRower();
    

private slots:
    void test_case1();
	
};

FTMSRower::FTMSRower()
{

}

FTMSRower::~FTMSRower()
{

}

void FTMSRower::test_case1()
{

}

QTEST_APPLESS_MAIN(FTMSRower)



#include "tst_ftmsrower.moc"


