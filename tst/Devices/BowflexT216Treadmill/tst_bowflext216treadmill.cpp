#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "bowflext216treadmill.h"

class BowflexT216Treadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(BowflexT216Treadmill)

	BowflexT216Treadmill();
    ~BowflexT216Treadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

BowflexT216Treadmill::BowflexT216Treadmill()
{

}

BowflexT216Treadmill::~BowflexT216Treadmill()
{

}

bool BowflexT216Treadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
    return dynamic_cast<bowflext216treadmill*>(detectedDevice)!=nullptr;
}

QStringList BowflexT216Treadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void BowflexT216Treadmill::test_case1()
{

}

DECLARE_TEST(BowflexT216Treadmill)

#include "tst_bowflext216treadmill.moc"
