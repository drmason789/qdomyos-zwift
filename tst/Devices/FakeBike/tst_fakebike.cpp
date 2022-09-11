#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FakeBike : public BluetoothDevice
{
    Q_OBJECT

public:
    FakeBike();
	~FakeBike();
    

private slots:
    void test_case1();
	
};

FakeBike::FakeBike()
{

}

FakeBike::~FakeBike()
{

}

void FakeBike::test_case1()
{

}

QTEST_APPLESS_MAIN(FakeBike)



#include "tst_fakebike.moc"


