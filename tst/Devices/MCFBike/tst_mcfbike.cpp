#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "mcfbike.h"

class MCFBike : public BluetoothDevice
{
	Q_OBJECT

public:
	MCFBike();
	~MCFBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

MCFBike::MCFBike()
{

}

MCFBike::~MCFBike()
{

}

bool MCFBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<mcfbike*>(detectedDevice)!=nullptr;	
}

QStringList MCFBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void MCFBike::test_case1()
{

}

QTEST_APPLESS_MAIN(MCFBike)



#include "tst_mcfbike.moc"


