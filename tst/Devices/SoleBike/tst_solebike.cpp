#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SoleBike : public BluetoothDevice
{
    Q_OBJECT

public:
    SoleBike();
	~SoleBike();
    

private slots:
    void test_case1();
	
};

SoleBike::SoleBike()
{

}

SoleBike::~SoleBike()
{

}

void SoleBike::test_case1()
{

}

QTEST_APPLESS_MAIN(SoleBike)



#include "tst_solebike.moc"


