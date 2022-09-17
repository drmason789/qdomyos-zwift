#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "npecablebike.h"

class NPECableBike : public BluetoothDevice
{
	Q_OBJECT

public:
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


