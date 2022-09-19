#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "yesoulbike.h"

class YesoulBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(YesoulBike)

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

DECLARE_TEST(YesoulBike)



#include "tst_yesoulbike.moc"


