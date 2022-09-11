#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class EchelonConnectSportBike : public BluetoothDevice
{
    Q_OBJECT

public:
    EchelonConnectSportBike();
	~EchelonConnectSportBike();
    

private slots:
    void test_case1();
	
};

EchelonConnectSportBike::EchelonConnectSportBike()
{

}

EchelonConnectSportBike::~EchelonConnectSportBike()
{

}

void EchelonConnectSportBike::test_case1()
{

}

QTEST_APPLESS_MAIN(EchelonConnectSportBike)



#include "tst_echelonconnectsport.moc"


