#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "nautilustreadmill.h"

class NautilusTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	NautilusTreadmill();
	~NautilusTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

NautilusTreadmill::NautilusTreadmill()
{

}

NautilusTreadmill::~NautilusTreadmill()
{

}

bool NautilusTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<nautilustreadmill*>(detectedDevice)!=nullptr;	
}

QStringList NautilusTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void NautilusTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(NautilusTreadmill)



#include "tst_nautilustreadmill.moc"


