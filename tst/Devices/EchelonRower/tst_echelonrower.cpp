#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class EchelonRower : public BluetoothDevice
{
    Q_OBJECT

public:
    EchelonRower();
	~EchelonRower();
    

private slots:
    void test_case1();
	
};

EchelonRower::EchelonRower()
{

}

EchelonRower::~EchelonRower()
{

}

void EchelonRower::test_case1()
{

}

QTEST_APPLESS_MAIN(EchelonRower)



#include "tst_echelonrower.moc"


