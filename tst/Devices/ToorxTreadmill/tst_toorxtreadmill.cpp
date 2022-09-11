#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class ToorxTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    ToorxTreadmill();
	~ToorxTreadmill();
    

private slots:
    void test_case1();
	
};

ToorxTreadmill::ToorxTreadmill()
{

}

ToorxTreadmill::~ToorxTreadmill()
{

}

void ToorxTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(ToorxTreadmill)



#include "tst_toorxtreadmill.moc"


