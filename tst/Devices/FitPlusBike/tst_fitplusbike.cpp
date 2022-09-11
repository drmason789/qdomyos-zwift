#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FitPlusBike : public BluetoothDevice
{
    Q_OBJECT

public:
    FitPlusBike();
	~FitPlusBike();
    

private slots:
    void test_case1();
	
};

FitPlusBike::FitPlusBike()
{

}

FitPlusBike::~FitPlusBike()
{

}

void FitPlusBike::test_case1()
{

}

QTEST_APPLESS_MAIN(FitPlusBike)



#include "tst_fitplusbike.moc"


