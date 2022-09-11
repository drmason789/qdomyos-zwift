#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class KingsmithR2Treadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    KingsmithR2Treadmill();
	~KingsmithR2Treadmill();
    

private slots:
    void test_case1();
	
};

KingsmithR2Treadmill::KingsmithR2Treadmill()
{

}

KingsmithR2Treadmill::~KingsmithR2Treadmill()
{

}

void KingsmithR2Treadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(KingsmithR2Treadmill)



#include "tst_kingsmithr2treadmill.moc"


