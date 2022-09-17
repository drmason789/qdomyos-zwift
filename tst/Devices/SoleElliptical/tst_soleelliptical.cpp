#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "soleelliptical.h"

class SoleElliptical : public BluetoothDevice
{
	Q_OBJECT

public:
	SoleElliptical();
	~SoleElliptical();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SoleElliptical::SoleElliptical()
{

}

SoleElliptical::~SoleElliptical()
{

}

bool SoleElliptical::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<soleelliptical*>(detectedDevice)!=nullptr;	
}

QStringList SoleElliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void SoleElliptical::test_case1()
{

}

DECLARE_TEST(SoleElliptical)



#include "tst_soleelliptical.moc"


