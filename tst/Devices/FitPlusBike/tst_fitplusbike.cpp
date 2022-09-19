#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "fitplusbike.h"

class FitPlusBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(FitPlusBike)

	FitPlusBike();
	~FitPlusBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

FitPlusBike::FitPlusBike()
{

}

FitPlusBike::~FitPlusBike()
{

}

bool FitPlusBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<fitplusbike*>(detectedDevice)!=nullptr;	
}

QStringList FitPlusBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void FitPlusBike::test_case1()
{

}

DECLARE_TEST(FitPlusBike)



#include "tst_fitplusbike.moc"


