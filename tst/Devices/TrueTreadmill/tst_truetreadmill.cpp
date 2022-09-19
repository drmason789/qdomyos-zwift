#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "truetreadmill.h"

class TrueTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	TrueTreadmill();
	~TrueTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

TrueTreadmill::TrueTreadmill()
{

}

TrueTreadmill::~TrueTreadmill()
{

}

bool TrueTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<truetreadmill*>(detectedDevice)!=nullptr;	
}

QStringList TrueTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void TrueTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(TrueTreadmill)



#include "tst_truetreadmill.moc"


