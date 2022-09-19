#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "proformbike.h"

class ProFormBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(ProFormBike)

	ProFormBike();
	~ProFormBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

ProFormBike::ProFormBike()
{

}

ProFormBike::~ProFormBike()
{

}

bool ProFormBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<proformbike*>(detectedDevice)!=nullptr;	
}

QStringList ProFormBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormBike::test_case1()
{

}

DECLARE_TEST(ProFormBike)



#include "tst_proformbike.moc"


