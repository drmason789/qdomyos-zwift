#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "domyoselliptical.h"

class DomyosElliptical : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(DomyosElliptical)

	DomyosElliptical();
	~DomyosElliptical();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

DomyosElliptical::DomyosElliptical()
{

}

DomyosElliptical::~DomyosElliptical()
{

}

bool DomyosElliptical::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<domyoselliptical*>(detectedDevice)!=nullptr;	
}

QStringList DomyosElliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void DomyosElliptical::test_case1()
{

}

DECLARE_TEST(DomyosElliptical)



#include "tst_domyoselliptical.moc"


