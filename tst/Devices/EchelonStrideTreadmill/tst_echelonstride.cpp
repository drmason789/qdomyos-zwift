#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "echelonstridetreadmill.h"

class EchelonStrideTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
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
	return dynamic_cast<echelonstridetreadmill*>(detectedDevice)!=nullptr;	
}

QStringList EchelonStrideTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void EchelonStrideTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(EchelonStrideTreadmill)



#include "tst_echelonstride.moc"


