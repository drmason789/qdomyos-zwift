#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class KingsmithR1ProTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    KingsmithR1ProTreadmill();
	~KingsmithR1ProTreadmill();
    

private slots:
    void test_case1();
	
};

KingsmithR1ProTreadmill::KingsmithR1ProTreadmill()
{

}

KingsmithR1ProTreadmill::~KingsmithR1ProTreadmill()
{

}

void KingsmithR1ProTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(KingsmithR1ProTreadmill)



#include "tst_kingsmithr1protreadmill.moc"


