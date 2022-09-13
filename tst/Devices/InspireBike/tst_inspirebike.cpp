#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "inspirebike.h"

class InspireBike : public BluetoothDevice
{
	Q_OBJECT

public:
	InspireBike();
	~InspireBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

InspireBike::InspireBike()
{

}

InspireBike::~InspireBike()
{

}

bool InspireBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<inspirebike*>(detectedDevice)!=nullptr;	
}

QStringList InspireBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void InspireBike::test_case1()
{

}

QTEST_APPLESS_MAIN(InspireBike)



#include "tst_inspirebike.moc"


