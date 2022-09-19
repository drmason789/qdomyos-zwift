#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "stagesbike.h"

class StagesBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(StagesBike)

	StagesBike();
	~StagesBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

StagesBike::StagesBike()
{

}

StagesBike::~StagesBike()
{

}

bool StagesBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<stagesbike*>(detectedDevice)!=nullptr;	
}

QStringList StagesBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void StagesBike::test_case1()
{

}

DECLARE_TEST(StagesBike)



#include "tst_stagesbike.moc"


