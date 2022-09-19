#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "octanetreadmill.h"

class OctaneTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(OctaneTreadmill)

	OctaneTreadmill();
	~OctaneTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

OctaneTreadmill::OctaneTreadmill()
{

}

OctaneTreadmill::~OctaneTreadmill()
{

}

bool OctaneTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<octanetreadmill*>(detectedDevice)!=nullptr;	
}

QStringList OctaneTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void OctaneTreadmill::test_case1()
{

}

DECLARE_TEST(OctaneTreadmill)



#include "tst_octanetreadmill.moc"


