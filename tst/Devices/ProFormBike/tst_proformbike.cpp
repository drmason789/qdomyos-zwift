#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class ProFormBike : public BluetoothDevice
{
    Q_OBJECT

public:
    ProFormBike();
	~ProFormBike();
    

private slots:
    void test_case1();
	
};

ProFormBike::ProFormBike()
{

}

ProFormBike::~ProFormBike()
{

}

void ProFormBike::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormBike)



#include "tst_proformbike.moc"


