#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "nordictrackifitadbtreadmill.h"

class NordicTrackIFitADBTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	NordicTrackIFitADBTreadmill();
	~NordicTrackIFitADBTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

NordicTrackIFitADBTreadmill::NordicTrackIFitADBTreadmill()
{

}

NordicTrackIFitADBTreadmill::~NordicTrackIFitADBTreadmill()
{

}

bool NordicTrackIFitADBTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<nordictrackifitadbtreadmill*>(detectedDevice)!=nullptr;	
}

QStringList NordicTrackIFitADBTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void NordicTrackIFitADBTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(NordicTrackIFitADBTreadmill)



#include "tst_nordictrackifitadbtreadmill.moc"


