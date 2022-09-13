#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "ftmsbike.h"

class FTMSBike : public BluetoothDevice
{
	Q_OBJECT

public:
	FTMSBike();
	~FTMSBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

FTMSBike::FTMSBike()
{

}

FTMSBike::~FTMSBike()
{

}

bool FTMSBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<ftmsbike*>(detectedDevice)!=nullptr;	
}

QStringList FTMSBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void FTMSBike::test_case1()
{

}

QTEST_APPLESS_MAIN(FTMSBike)



#include "tst_ftmsbike.moc"


