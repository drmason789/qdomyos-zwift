#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "iconceptbike.h"

class iConceptBike : public BluetoothDevice
{
	Q_OBJECT

public:
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

QTEST_APPLESS_MAIN(iConceptBike)



#include "tst_iconceptbike.moc"


