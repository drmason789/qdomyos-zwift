#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class EchelonStrideTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    EchelonStrideTreadmill();
	~EchelonStrideTreadmill();
    

private slots:
    void test_case1();
	
};

EchelonStrideTreadmill::EchelonStrideTreadmill()
{

}

EchelonStrideTreadmill::~EchelonStrideTreadmill()
{

}

void EchelonStrideTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(EchelonStrideTreadmill)



#include "tst_echelonstride.moc"


