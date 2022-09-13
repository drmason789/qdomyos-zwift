#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "cscbike.h"

class CSCBike : public BluetoothDevice
{
	Q_OBJECT

public:
	CSCBike();
	~CSCBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

CSCBike::CSCBike()
{

}

CSCBike::~CSCBike()
{

}

bool CSCBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<cscbike*>(detectedDevice)!=nullptr;	
}

QStringList CSCBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void CSCBike::test_case1()
{

}

QTEST_APPLESS_MAIN(CSCBike)



#include "tst_cscbike.moc"


