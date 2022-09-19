#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "proformwifibike.h"

class ProFormWiFiBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(ProFormWiFiBike)

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

DECLARE_TEST(ProFormWiFiBike)



#include "tst_proformwifibike.moc"


