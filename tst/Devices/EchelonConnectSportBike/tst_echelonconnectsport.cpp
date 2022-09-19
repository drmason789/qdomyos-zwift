#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "echelonconnectsport.h"

class EchelonConnectSportBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(EchelonConnectSportBike)

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
    return dynamic_cast<echelonconnectsport*>(detectedDevice)!=nullptr;
}

QStringList EchelonConnectSportBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void EchelonConnectSportBike::test_case1()
{

}

DECLARE_TEST(EchelonConnectSportBike)



#include "tst_echelonconnectsport.moc"


