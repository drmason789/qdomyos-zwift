#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "technogymmyruntreadmill.h"

class TechnoGymMyRunTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(TechnoGymMyRunTreadmill)

	TechnoGymMyRunTreadmill();
	~TechnoGymMyRunTreadmill();

	QStringList get_deviceNames() override;
    bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

TechnoGymMyRunTreadmill::TechnoGymMyRunTreadmill()
{

}

TechnoGymMyRunTreadmill::~TechnoGymMyRunTreadmill()
{

}

bool TechnoGymMyRunTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<technogymmyruntreadmill*>(detectedDevice)!=nullptr;	
}

QStringList TechnoGymMyRunTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void TechnoGymMyRunTreadmill::test_case1()
{

}

DECLARE_TEST(TechnoGymMyRunTreadmill)



#include "tst_technogymmyruntreadmill.moc"


