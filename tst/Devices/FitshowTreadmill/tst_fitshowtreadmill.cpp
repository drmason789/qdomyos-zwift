#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FitshowTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    FitshowTreadmill();
	~FitshowTreadmill();
    

private slots:
    void test_case1();
	
};

FitshowTreadmill::FitshowTreadmill()
{

}

FitshowTreadmill::~FitshowTreadmill()
{

}

void FitshowTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(FitshowTreadmill)



#include "tst_fitshowtreadmill.moc"


