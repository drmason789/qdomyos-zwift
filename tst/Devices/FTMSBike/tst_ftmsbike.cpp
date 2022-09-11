#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FTMSBike : public BluetoothDevice
{
    Q_OBJECT

public:
    FTMSBike();
	~FTMSBike();
    

private slots:
    void test_case1();
	
};

FTMSBike::FTMSBike()
{

}

FTMSBike::~FTMSBike()
{

}

void FTMSBike::test_case1()
{

}

QTEST_APPLESS_MAIN(FTMSBike)



#include "tst_ftmsbike.moc"


