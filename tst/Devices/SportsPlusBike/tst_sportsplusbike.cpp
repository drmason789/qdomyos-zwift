#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "sportsplusbike.h"

class SportsPlusBike : public BluetoothDevice
{
	Q_OBJECT

public:
	SportsPlusBike();
	~SportsPlusBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SportsPlusBike::SportsPlusBike()
{

}

SportsPlusBike::~SportsPlusBike()
{

}

bool SportsPlusBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<sportsplusbike*>(detectedDevice)!=nullptr;	
}

QStringList SportsPlusBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void SportsPlusBike::test_case1()
{

}

DECLARE_TEST(SportsPlusBike)



#include "tst_sportsplusbike.moc"


