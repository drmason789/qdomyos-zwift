#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FlywheelBike : public BluetoothDevice
{
    Q_OBJECT

public:
    FlywheelBike();
	~FlywheelBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

FlywheelBike::FlywheelBike()
{

}

FlywheelBike::~FlywheelBike()
{

}

QStringList FlywheelBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void FlywheelBike::test_case1()
{

}

QTEST_APPLESS_MAIN(FlywheelBike)



#include "tst_flywheelbike.moc"


