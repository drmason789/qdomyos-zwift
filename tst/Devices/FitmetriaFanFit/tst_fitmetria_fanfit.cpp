#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FitmetriaFanFit : public BluetoothDevice
{
    Q_OBJECT

public:
    FitmetriaFanFit();
	~FitmetriaFanFit();
    

private slots:
    void test_case1();
	
};

FitmetriaFanFit::FitmetriaFanFit()
{

}

FitmetriaFanFit::~FitmetriaFanFit()
{

}

void FitmetriaFanFit::test_case1()
{

}

QTEST_APPLESS_MAIN(FitmetriaFanFit)



#include "tst_fitmetria_fanfit.moc"


