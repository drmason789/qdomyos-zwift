#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "fitmetria_fanfit.h"

class FitmetriaFanFit : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(FitmetriaFanFit)

	FitmetriaFanFit();
	~FitmetriaFanFit();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

FitmetriaFanFit::FitmetriaFanFit()
{

}

FitmetriaFanFit::~FitmetriaFanFit()
{

}

bool FitmetriaFanFit::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
    return dynamic_cast<fitmetria_fanfit*>(detectedDevice)!=nullptr;
}

QStringList FitmetriaFanFit::get_deviceNames() {
	QStringList result;
	return result;
 }

void FitmetriaFanFit::test_case1()
{

}

DECLARE_TEST(FitmetriaFanFit)



#include "tst_fitmetria_fanfit.moc"


