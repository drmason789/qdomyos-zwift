#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class TrueTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    TrueTreadmill();
	~TrueTreadmill();
    

private slots:
    void test_case1();
	
};

TrueTreadmill::TrueTreadmill()
{

}

TrueTreadmill::~TrueTreadmill()
{

}

void TrueTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(TrueTreadmill)



#include "tst_truetreadmill.moc"


