#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "heartratebelt.h"

class HeartRateBelt : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(HeartRateBelt)

	HeartRateBelt();
	~HeartRateBelt();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

HeartRateBelt::HeartRateBelt()
{

}

HeartRateBelt::~HeartRateBelt()
{

}

bool HeartRateBelt::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<heartratebelt*>(detectedDevice)!=nullptr;	
}

QStringList HeartRateBelt::get_deviceNames() {
	QStringList result;
	return result;
 }

void HeartRateBelt::test_case1()
{

}

DECLARE_TEST(HeartRateBelt)



#include "tst_heartratebelt.moc"


