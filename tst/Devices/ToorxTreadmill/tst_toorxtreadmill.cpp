#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "toorxtreadmill.h"

class ToorxTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(ToorxTreadmill)

	ToorxTreadmill();
	~ToorxTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

ToorxTreadmill::ToorxTreadmill()
{

}

ToorxTreadmill::~ToorxTreadmill()
{

}

bool ToorxTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<toorxtreadmill*>(detectedDevice)!=nullptr;	
}

QStringList ToorxTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void ToorxTreadmill::test_case1()
{

}

DECLARE_TEST(ToorxTreadmill)



#include "tst_toorxtreadmill.moc"


