#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "proformwifibike.h"

class ProFormWiFiBike : public BluetoothDevice
{
	Q_OBJECT

public:
	ProFormWiFiBike();
	~ProFormWiFiBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

ProFormWiFiBike::ProFormWiFiBike()
{

}

ProFormWiFiBike::~ProFormWiFiBike()
{

}

bool ProFormWiFiBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<proformwifibike*>(detectedDevice)!=nullptr;	
}

QStringList ProFormWiFiBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormWiFiBike::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormWiFiBike)



#include "tst_proformwifibike.moc"


