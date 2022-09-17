#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "proformrower.h"

class ProFormRower : public BluetoothDevice
{
	Q_OBJECT

public:
	ProFormRower();
	~ProFormRower();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

ProFormRower::ProFormRower()
{

}

ProFormRower::~ProFormRower()
{

}

bool ProFormRower::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<proformrower*>(detectedDevice)!=nullptr;	
}

QStringList ProFormRower::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormRower::test_case1()
{

}

DECLARE_TEST(ProFormRower)



#include "tst_proformrower.moc"


