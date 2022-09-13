#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "shuaa5treadmill.h"

class Shuaa5Treadmill : public BluetoothDevice
{
	Q_OBJECT

public:
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

QTEST_APPLESS_MAIN(Shuaa5Treadmill)



#include "tst_shuaa5treadmill.moc"


