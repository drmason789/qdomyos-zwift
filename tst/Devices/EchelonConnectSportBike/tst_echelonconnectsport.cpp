#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class EchelonConnectSportBike : public BluetoothDevice
{
    Q_OBJECT

public:
    EchelonConnectSportBike();
	~EchelonConnectSportBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

EchelonConnectSportBike::EchelonConnectSportBike()
{

}

EchelonConnectSportBike::~EchelonConnectSportBike()
{

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


