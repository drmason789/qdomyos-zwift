#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "shuaa5treadmill.h"

class Shuaa5Treadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(Shuaa5Treadmill)

	Shuaa5Treadmill();
	~Shuaa5Treadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

Shuaa5Treadmill::Shuaa5Treadmill()
{

}

Shuaa5Treadmill::~Shuaa5Treadmill()
{

}

bool Shuaa5Treadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<shuaa5treadmill*>(detectedDevice)!=nullptr;	
}

QStringList Shuaa5Treadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void Shuaa5Treadmill::test_case1()
{

}

DECLARE_TEST(Shuaa5Treadmill)



#include "tst_shuaa5treadmill.moc"


