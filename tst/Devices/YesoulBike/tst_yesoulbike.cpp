#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "yesoulbike.h"

class YesoulBike : public BluetoothDevice
{
	Q_OBJECT

public:
	YesoulBike();
	~YesoulBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

YesoulBike::YesoulBike()
{

}

YesoulBike::~YesoulBike()
{

}

bool YesoulBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<yesoulbike*>(detectedDevice)!=nullptr;	
}

QStringList YesoulBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void YesoulBike::test_case1()
{

}

QTEST_APPLESS_MAIN(YesoulBike)



#include "tst_yesoulbike.moc"


