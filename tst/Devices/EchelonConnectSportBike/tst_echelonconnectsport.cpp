#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "echelonconnectsportbike.h"

class EchelonConnectSportBike : public BluetoothDevice
{
	Q_OBJECT

public:
	EchelonConnectSportBike();
	~EchelonConnectSportBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

EchelonConnectSportBike::EchelonConnectSportBike()
{

}

EchelonConnectSportBike::~EchelonConnectSportBike()
{

}

bool EchelonConnectSportBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<echelonconnectsportbike*>(detectedDevice)!=nullptr;	
}

QStringList EchelonConnectSportBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void EchelonConnectSportBike::test_case1()
{

}

QTEST_APPLESS_MAIN(EchelonConnectSportBike)



#include "tst_echelonconnectsport.moc"


