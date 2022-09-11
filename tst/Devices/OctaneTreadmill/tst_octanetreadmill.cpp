#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class OctaneTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    OctaneTreadmill();
	~OctaneTreadmill();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

OctaneTreadmill::OctaneTreadmill()
{

}

OctaneTreadmill::~OctaneTreadmill()
{

}

QStringList OctaneTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void OctaneTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(OctaneTreadmill)



#include "tst_octanetreadmill.moc"


