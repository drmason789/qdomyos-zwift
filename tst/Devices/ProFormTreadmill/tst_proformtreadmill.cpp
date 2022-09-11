#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class ProFormTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    ProFormTreadmill();
	~ProFormTreadmill();
    

private slots:
    void test_case1();
	
};

ProFormTreadmill::ProFormTreadmill()
{

}

ProFormTreadmill::~ProFormTreadmill()
{

}

void ProFormTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormTreadmill)



#include "tst_proformtreadmill.moc"


