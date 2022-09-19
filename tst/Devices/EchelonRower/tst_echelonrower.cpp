#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "echelonrower.h"

class EchelonRower : public BluetoothDevice
{
	Q_OBJECT

public:
	EchelonRower();
	~EchelonRower();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

EchelonRower::EchelonRower()
{

}

EchelonRower::~EchelonRower()
{

}

bool EchelonRower::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<echelonrower*>(detectedDevice)!=nullptr;	
}

QStringList EchelonRower::get_deviceNames() {
	QStringList result;
	return result;
 }

void EchelonRower::test_case1()
{

}

QTEST_APPLESS_MAIN(EchelonRower)



#include "tst_echelonrower.moc"


