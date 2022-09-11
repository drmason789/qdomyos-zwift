#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class EliteSterzoSmart : public BluetoothDevice
{
    Q_OBJECT

public:
    EliteSterzoSmart();
	~EliteSterzoSmart();
    

private slots:
    void test_case1();
	
};

EliteSterzoSmart::EliteSterzoSmart()
{

}

EliteSterzoSmart::~EliteSterzoSmart()
{

}

void EliteSterzoSmart::test_case1()
{

}

QTEST_APPLESS_MAIN(EliteSterzoSmart)



#include "tst_elitesterzosmart.moc"


