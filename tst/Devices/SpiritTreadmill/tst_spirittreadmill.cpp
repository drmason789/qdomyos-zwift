#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "spirittreadmill.h"

class SpiritTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	SpiritTreadmill();
	~SpiritTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SpiritTreadmill::SpiritTreadmill()
{

}

SpiritTreadmill::~SpiritTreadmill()
{

}

bool SpiritTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<spirittreadmill*>(detectedDevice)!=nullptr;	
}

QStringList SpiritTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void SpiritTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(SpiritTreadmill)



#include "tst_spirittreadmill.moc"


