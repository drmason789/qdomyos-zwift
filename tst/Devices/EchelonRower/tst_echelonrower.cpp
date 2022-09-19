#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "echelonrower.h"

class EchelonRower : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(EchelonRower)

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

DECLARE_TEST(EchelonRower)



#include "tst_echelonrower.moc"


