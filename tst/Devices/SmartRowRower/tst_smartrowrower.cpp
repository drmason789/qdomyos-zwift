#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "smartrowrower.h"

class SmartRowRower : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(SmartRowRower)

	SmartRowRower();
	~SmartRowRower();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SmartRowRower::SmartRowRower()
{

}

SmartRowRower::~SmartRowRower()
{

}

bool SmartRowRower::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<smartrowrower*>(detectedDevice)!=nullptr;	
}

QStringList SmartRowRower::get_deviceNames() {
	QStringList result;
	return result;
 }

void SmartRowRower::test_case1()
{

}

DECLARE_TEST(SmartRowRower)



#include "tst_smartrowrower.moc"


