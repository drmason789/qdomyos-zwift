#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "skandikawirybike.h"

class SkandikaWiryBike : public BluetoothDevice
{
	Q_OBJECT

public:
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
	return dynamic_cast<skandikawirybike*>(detectedDevice)!=nullptr;	
}

QStringList SkandikaWiryBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void SkandikaWiryBike::test_case1()
{

}

QTEST_APPLESS_MAIN(SkandikaWiryBike)



#include "tst_skandikawiribike.moc"


