#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "iconceptbike.h"

class iConceptBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(iConceptBike)

	iConceptBike();
	~iConceptBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

iConceptBike::iConceptBike()
{

}

iConceptBike::~iConceptBike()
{

}

bool iConceptBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<iconceptbike*>(detectedDevice)!=nullptr;	
}

QStringList iConceptBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void iConceptBike::test_case1()
{

}

DECLARE_TEST(iConceptBike)



#include "tst_iconceptbike.moc"


