#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class TacxNeo2 : public BluetoothDevice
{
    Q_OBJECT

public:
    TacxNeo2();
	~TacxNeo2();
    

private slots:
    void test_case1();
	
};

TacxNeo2::TacxNeo2()
{

}

TacxNeo2::~TacxNeo2()
{

}

void TacxNeo2::test_case1()
{

}

QTEST_APPLESS_MAIN(TacxNeo2)



#include "tst_tacxneo2.moc"


