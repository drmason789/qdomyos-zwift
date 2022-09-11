#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class EliteRizer : public BluetoothDevice
{
    Q_OBJECT

public:
    EliteRizer();
	~EliteRizer();
    

private slots:
    void test_case1();
	
};

EliteRizer::EliteRizer()
{

}

EliteRizer::~EliteRizer()
{

}

void EliteRizer::test_case1()
{

}

QTEST_APPLESS_MAIN(EliteRizer)



#include "tst_eliterizer.moc"


