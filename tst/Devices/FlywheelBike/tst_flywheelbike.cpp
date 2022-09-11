#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FlywheelBike : public BluetoothDevice
{
    Q_OBJECT

public:
    FlywheelBike();
	~FlywheelBike();
    

private slots:
    void test_case1();
	
};

FlywheelBike::FlywheelBike()
{

}

FlywheelBike::~FlywheelBike()
{

}

void FlywheelBike::test_case1()
{

}

QTEST_APPLESS_MAIN(FlywheelBike)



#include "tst_flywheelbike.moc"


