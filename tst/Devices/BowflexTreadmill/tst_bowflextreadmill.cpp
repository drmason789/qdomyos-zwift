#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "bowflextreadmill.h"

class BowflexTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(BowflexTreadmill)

	BowflexTreadmill();
	~BowflexTreadmill();

    QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

BowflexTreadmill::BowflexTreadmill()
{

}

BowflexTreadmill::~BowflexTreadmill()
{

}

bool BowflexTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<bowflextreadmill*>(detectedDevice)!=nullptr;	
}

QStringList BowflexTreadmill::get_deviceNames() {
    QStringList result;
    return result;
}

void BowflexTreadmill::test_case1()
{

}

DECLARE_TEST(BowflexTreadmill)


#include "tst_bowflextreadmill.moc"



