#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "skandikawiribike.h"

class SkandikaWiryBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(SkandikaWiryBike)

	SkandikaWiryBike();
	~SkandikaWiryBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SkandikaWiryBike::SkandikaWiryBike()
{

}

SkandikaWiryBike::~SkandikaWiryBike()
{

}

bool SkandikaWiryBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
    return dynamic_cast<skandikawiribike*>(detectedDevice)!=nullptr;
}

QStringList SkandikaWiryBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void SkandikaWiryBike::test_case1()
{

}

DECLARE_TEST(SkandikaWiryBike)



#include "tst_skandikawiribike.moc"


