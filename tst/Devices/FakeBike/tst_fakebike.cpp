#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "fakebike.h"

class FakeBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(FakeBike)

	FakeBike();
	~FakeBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

FakeBike::FakeBike()
{

}

FakeBike::~FakeBike()
{

}

bool FakeBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<fakebike*>(detectedDevice)!=nullptr;	
}

QStringList FakeBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void FakeBike::test_case1()
{

}

DECLARE_TEST(FakeBike)



#include "tst_fakebike.moc"


