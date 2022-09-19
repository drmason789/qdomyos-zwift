#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "horizontreadmill.h"

class HorizonTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(HorizonTreadmill)

	HorizonTreadmill();
	~HorizonTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

HorizonTreadmill::HorizonTreadmill()
{

}

HorizonTreadmill::~HorizonTreadmill()
{

}

bool HorizonTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<horizontreadmill*>(detectedDevice)!=nullptr;	
}

QStringList HorizonTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void HorizonTreadmill::test_case1()
{

}

DECLARE_TEST(HorizonTreadmill)



#include "tst_horizontreadmill.moc"


