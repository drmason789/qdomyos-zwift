#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "treadmill.h"

class Treadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(Treadmill)

	Treadmill();
	~Treadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

Treadmill::Treadmill()
{

}

Treadmill::~Treadmill()
{

}

bool Treadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<treadmill*>(detectedDevice)!=nullptr;	
}

QStringList Treadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void Treadmill::test_case1()
{

}

DECLARE_TEST(Treadmill)



#include "tst_treadmill.moc"


