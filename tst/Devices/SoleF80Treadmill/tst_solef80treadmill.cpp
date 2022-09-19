#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "solef80treadmill.h"

class SoleF80Treadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(SoleF80Treadmill)

	SoleF80Treadmill();
	~SoleF80Treadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SoleF80Treadmill::SoleF80Treadmill()
{

}

SoleF80Treadmill::~SoleF80Treadmill()
{

}

bool SoleF80Treadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<solef80treadmill*>(detectedDevice)!=nullptr;	
}

QStringList SoleF80Treadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void SoleF80Treadmill::test_case1()
{

}

DECLARE_TEST(SoleF80Treadmill)



#include "tst_solef80treadmill.moc"


