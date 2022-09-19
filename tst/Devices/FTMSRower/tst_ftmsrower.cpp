#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "ftmsrower.h"

class FTMSRower : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(FTMSRower)

	FTMSRower();
	~FTMSRower();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

FTMSRower::FTMSRower()
{

}

FTMSRower::~FTMSRower()
{

}

bool FTMSRower::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<ftmsrower*>(detectedDevice)!=nullptr;	
}

QStringList FTMSRower::get_deviceNames() {
	QStringList result;
	return result;
 }

void FTMSRower::test_case1()
{

}

DECLARE_TEST(FTMSRower)



#include "tst_ftmsrower.moc"


