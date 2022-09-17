#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "elliptical.h"

class Elliptical : public BluetoothDevice
{
	Q_OBJECT

public:
	Elliptical();
	~Elliptical();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

Elliptical::Elliptical()
{

}

Elliptical::~Elliptical()
{

}

bool Elliptical::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<elliptical*>(detectedDevice)!=nullptr;	
}

QStringList Elliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void Elliptical::test_case1()
{

}

DECLARE_TEST(Elliptical)



#include "tst_elliptical.moc"


