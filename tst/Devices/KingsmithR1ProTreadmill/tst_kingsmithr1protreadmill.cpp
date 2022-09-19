#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "kingsmithr1protreadmill.h"

class KingsmithR1ProTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	KingsmithR1ProTreadmill();
	~KingsmithR1ProTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

KingsmithR1ProTreadmill::KingsmithR1ProTreadmill()
{

}

KingsmithR1ProTreadmill::~KingsmithR1ProTreadmill()
{

}

bool KingsmithR1ProTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<kingsmithr1protreadmill*>(detectedDevice)!=nullptr;	
}

QStringList KingsmithR1ProTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void KingsmithR1ProTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(KingsmithR1ProTreadmill)



#include "tst_kingsmithr1protreadmill.moc"


