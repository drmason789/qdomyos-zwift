#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "eslinkertreadmill.h"

class ESLinkerTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	ESLinkerTreadmill();
	~ESLinkerTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

ESLinkerTreadmill::ESLinkerTreadmill()
{

}

ESLinkerTreadmill::~ESLinkerTreadmill()
{

}

bool ESLinkerTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<eslinkertreadmill*>(detectedDevice)!=nullptr;	
}

QStringList ESLinkerTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void ESLinkerTreadmill::test_case1()
{

}

DECLARE_TEST(ESLinkerTreadmill)



#include "tst_eslinkertreadmill.moc"


