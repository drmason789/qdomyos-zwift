#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "smartspin2k.h"

class SmartSpin2k : public BluetoothDevice
{
	Q_OBJECT

public:
	SmartSpin2k();
	~SmartSpin2k();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SmartSpin2k::SmartSpin2k()
{

}

SmartSpin2k::~SmartSpin2k()
{

}

bool SmartSpin2k::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<smartspin2k*>(detectedDevice)!=nullptr;	
}

QStringList SmartSpin2k::get_deviceNames() {
	QStringList result;
	return result;
 }

void SmartSpin2k::test_case1()
{

}

DECLARE_TEST(SmartSpin2k)



#include "tst_smartspin2k.moc"


