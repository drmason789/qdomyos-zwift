#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "sportstechbike.h"

class SportsTechBike : public BluetoothDevice
{
	Q_OBJECT

public:
	SportsTechBike();
	~SportsTechBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SportsTechBike::SportsTechBike()
{

}

SportsTechBike::~SportsTechBike()
{

}

bool SportsTechBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<sportstechbike*>(detectedDevice)!=nullptr;	
}

QStringList SportsTechBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void SportsTechBike::test_case1()
{

}

DECLARE_TEST(SportsTechBike)



#include "tst_sportstechbike.moc"


