#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class PafersTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    PafersTreadmill();
	~PafersTreadmill();
    

private slots:
    void test_case1();
	
};

PafersTreadmill::PafersTreadmill()
{

}

PafersTreadmill::~PafersTreadmill()
{

}

void PafersTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(PafersTreadmill)



#include "tst_paferstreadmill.moc"


