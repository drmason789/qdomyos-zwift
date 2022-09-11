#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class TrxAppGateUSBBike : public BluetoothDevice
{
    Q_OBJECT

public:
    TrxAppGateUSBBike();
	~TrxAppGateUSBBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

TrxAppGateUSBBike::TrxAppGateUSBBike()
{

}

TrxAppGateUSBBike::~TrxAppGateUSBBike()
{

}

QStringList TrxAppGateUSBBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void TrxAppGateUSBBike::test_case1()
{

}

QTEST_APPLESS_MAIN(TrxAppGateUSBBike)



#include "tst_trxappgateusbbike.moc"


