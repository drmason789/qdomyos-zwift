#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class KeepBike : public BluetoothDevice
{
    Q_OBJECT

public:
    KeepBike();
	~KeepBike();
    

private slots:
    void test_case1();
	
};

KeepBike::KeepBike()
{

}

KeepBike::~KeepBike()
{

}

void KeepBike::test_case1()
{

}

QTEST_APPLESS_MAIN(KeepBike)



#include "tst_keepbike.moc"


