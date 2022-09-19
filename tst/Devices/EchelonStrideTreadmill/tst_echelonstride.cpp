#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"
#include "echelonstride.h"

class EchelonStrideTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(EchelonStrideTreadmill)

	EchelonStrideTreadmill();
	~EchelonStrideTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

EchelonStrideTreadmill::EchelonStrideTreadmill()
{

}

EchelonStrideTreadmill::~EchelonStrideTreadmill()
{

}

bool EchelonStrideTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
    return dynamic_cast<echelonstride*>(detectedDevice)!=nullptr;
}

QStringList EchelonStrideTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void EchelonStrideTreadmill::test_case1()
{

}

DECLARE_TEST(EchelonStrideTreadmill)



#include "tst_echelonstride.moc"


