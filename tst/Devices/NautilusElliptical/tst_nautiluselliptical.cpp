#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "nautiluselliptical.h"

class NautilusElliptical : public BluetoothDevice
{
	Q_OBJECT

public:
	NautilusElliptical();
	~NautilusElliptical();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

NautilusElliptical::NautilusElliptical()
{

}

NautilusElliptical::~NautilusElliptical()
{

}

bool NautilusElliptical::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<nautiluselliptical*>(detectedDevice)!=nullptr;	
}

QStringList NautilusElliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void NautilusElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(NautilusElliptical)



#include "tst_nautiluselliptical.moc"


