#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "proformwifitreadmill.h"

class ProFormWiFiTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	ProFormWiFiTreadmill();
	~ProFormWiFiTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

ProFormWiFiTreadmill::ProFormWiFiTreadmill()
{

}

ProFormWiFiTreadmill::~ProFormWiFiTreadmill()
{

}

bool ProFormWiFiTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<proformwifitreadmill*>(detectedDevice)!=nullptr;	
}

QStringList ProFormWiFiTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormWiFiTreadmill::test_case1()
{

}

DECLARE_TEST(ProFormWiFiTreadmill)



#include "tst_proformwifitreadmill.moc"


