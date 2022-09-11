#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class TrxAppGateUSBTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    TrxAppGateUSBTreadmill();
	~TrxAppGateUSBTreadmill();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

TrxAppGateUSBTreadmill::TrxAppGateUSBTreadmill()
{

}

TrxAppGateUSBTreadmill::~TrxAppGateUSBTreadmill()
{

}

QStringList TrxAppGateUSBTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void TrxAppGateUSBTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(TrxAppGateUSBTreadmill)



#include "tst_trxappgateusbtreadmill.moc"


