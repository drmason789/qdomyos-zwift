#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SportsTechBike : public BluetoothDevice
{
    Q_OBJECT

public:
    SportsTechBike();
	~SportsTechBike();
    

private slots:
    void test_case1();
	
};

SportsTechBike::SportsTechBike()
{

}

SportsTechBike::~SportsTechBike()
{

}

void SportsTechBike::test_case1()
{

}

QTEST_APPLESS_MAIN(SportsTechBike)



#include "tst_sportstechbike.moc"


