#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "trxappgateusbtreadmill.h"

class TrxAppGateUSBTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(TrxAppGateUSBTreadmill)

	TrxAppGateUSBTreadmill();
	~TrxAppGateUSBTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

TrxAppGateUSBTreadmill::TrxAppGateUSBTreadmill()
{

}

TrxAppGateUSBTreadmill::~TrxAppGateUSBTreadmill()
{

}

bool TrxAppGateUSBTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<trxappgateusbtreadmill*>(detectedDevice)!=nullptr;	
}

QStringList TrxAppGateUSBTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void TrxAppGateUSBTreadmill::test_case1()
{

}

DECLARE_TEST(TrxAppGateUSBTreadmill)



#include "tst_trxappgateusbtreadmill.moc"


