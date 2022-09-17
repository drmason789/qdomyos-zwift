#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "trxappgateusbbike.h"

class TrxAppGateUSBBike : public BluetoothDevice
{
	Q_OBJECT

public:
	TrxAppGateUSBBike();
	~TrxAppGateUSBBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

TrxAppGateUSBBike::TrxAppGateUSBBike()
{

}

TrxAppGateUSBBike::~TrxAppGateUSBBike()
{

}

bool TrxAppGateUSBBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<trxappgateusbbike*>(detectedDevice)!=nullptr;	
}

QStringList TrxAppGateUSBBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void TrxAppGateUSBBike::test_case1()
{

}

DECLARE_TEST(TrxAppGateUSBBike)



#include "tst_trxappgateusbbike.moc"


