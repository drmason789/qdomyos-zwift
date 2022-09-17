#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "paferstreadmill.h"

class PafersTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	PafersTreadmill();
	~PafersTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

PafersTreadmill::PafersTreadmill()
{

}

PafersTreadmill::~PafersTreadmill()
{

}

bool PafersTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<paferstreadmill*>(detectedDevice)!=nullptr;	
}

QStringList PafersTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void PafersTreadmill::test_case1()
{

}

DECLARE_TEST(PafersTreadmill)



#include "tst_paferstreadmill.moc"


