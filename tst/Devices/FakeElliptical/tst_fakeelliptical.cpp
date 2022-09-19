#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "fakeelliptical.h"

class FakeElliptical : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(FakeElliptical)

	FakeElliptical();
	~FakeElliptical();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

FakeElliptical::FakeElliptical()
{

}

FakeElliptical::~FakeElliptical()
{

}

bool FakeElliptical::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<fakeelliptical*>(detectedDevice)!=nullptr;	
}

QStringList FakeElliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void FakeElliptical::test_case1()
{

}

DECLARE_TEST(FakeElliptical)



#include "tst_fakeelliptical.moc"


