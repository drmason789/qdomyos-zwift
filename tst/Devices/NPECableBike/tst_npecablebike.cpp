#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "npecablebike.h"

class NPECableBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(NPECableBike)

	NPECableBike();
	~NPECableBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

NPECableBike::NPECableBike()
{

}

NPECableBike::~NPECableBike()
{

}

bool NPECableBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<npecablebike*>(detectedDevice)!=nullptr;	
}

QStringList NPECableBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void NPECableBike::test_case1()
{

}

DECLARE_TEST(NPECableBike)



#include "tst_npecablebike.moc"


