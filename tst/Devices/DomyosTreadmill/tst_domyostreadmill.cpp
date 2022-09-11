#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class DomyosTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    DomyosTreadmill();
	~DomyosTreadmill();
    

private slots:
    void test_case1();
	
};

DomyosTreadmill::DomyosTreadmill()
{

}

DomyosTreadmill::~DomyosTreadmill()
{

}

void DomyosTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(DomyosTreadmill)



#include "tst_domyostreadmill.moc"


