#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "kingsmithr2treadmill.h"

class KingsmithR2Treadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	KingsmithR2Treadmill();
	~KingsmithR2Treadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

KingsmithR2Treadmill::KingsmithR2Treadmill()
{

}

KingsmithR2Treadmill::~KingsmithR2Treadmill()
{

}

bool KingsmithR2Treadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<kingsmithr2treadmill*>(detectedDevice)!=nullptr;	
}

QStringList KingsmithR2Treadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void KingsmithR2Treadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(KingsmithR2Treadmill)



#include "tst_kingsmithr2treadmill.moc"


