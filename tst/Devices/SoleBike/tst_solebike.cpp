#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "solebike.h"

class SoleBike : public BluetoothDevice
{
	Q_OBJECT

public:
	SoleBike();
	~SoleBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SoleBike::SoleBike()
{

}

SoleBike::~SoleBike()
{

}

bool SoleBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<solebike*>(detectedDevice)!=nullptr;	
}

QStringList SoleBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void SoleBike::test_case1()
{

}

QTEST_APPLESS_MAIN(SoleBike)



#include "tst_solebike.moc"


