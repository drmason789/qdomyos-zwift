#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class DomyosRower : public BluetoothDevice
{
    Q_OBJECT

public:
    DomyosRower();
	~DomyosRower();
    

private slots:
    void test_case1();
	
};

DomyosRower::DomyosRower()
{

}

DomyosRower::~DomyosRower()
{

}

void DomyosRower::test_case1()
{

}

QTEST_APPLESS_MAIN(DomyosRower)



#include "tst_domyosrower.moc"


