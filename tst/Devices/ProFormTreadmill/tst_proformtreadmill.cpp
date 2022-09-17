#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "proformtreadmill.h"

class ProFormTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	ProFormTreadmill();
	~ProFormTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

ProFormTreadmill::ProFormTreadmill()
{

}

ProFormTreadmill::~ProFormTreadmill()
{

}

bool ProFormTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<proformtreadmill*>(detectedDevice)!=nullptr;	
}

QStringList ProFormTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormTreadmill::test_case1()
{

}

DECLARE_TEST(ProFormTreadmill)



#include "tst_proformtreadmill.moc"


