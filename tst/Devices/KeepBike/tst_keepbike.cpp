#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "keepbike.h"

class KeepBike : public BluetoothDevice
{
	Q_OBJECT

public:
	KeepBike();
	~KeepBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

KeepBike::KeepBike()
{

}

KeepBike::~KeepBike()
{

}

bool KeepBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<keepbike*>(detectedDevice)!=nullptr;	
}

QStringList KeepBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void KeepBike::test_case1()
{

}

DECLARE_TEST(KeepBike)



#include "tst_keepbike.moc"


