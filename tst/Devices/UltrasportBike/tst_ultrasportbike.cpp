#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "ultrasportbike.h"

class UltrasportBike : public BluetoothDevice
{
	Q_OBJECT

public:
	UltrasportBike();
	~UltrasportBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

UltrasportBike::UltrasportBike()
{

}

UltrasportBike::~UltrasportBike()
{

}

bool UltrasportBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<ultrasportbike*>(detectedDevice)!=nullptr;	
}

QStringList UltrasportBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void UltrasportBike::test_case1()
{

}

QTEST_APPLESS_MAIN(UltrasportBike)



#include "tst_ultrasportbike.moc"


