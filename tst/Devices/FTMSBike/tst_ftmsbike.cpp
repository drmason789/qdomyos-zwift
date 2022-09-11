#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FTMSBike : public BluetoothDevice
{
    Q_OBJECT

public:
    FTMSBike();
	~FTMSBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

FTMSBike::FTMSBike()
{

}

FTMSBike::~FTMSBike()
{

}

QStringList FTMSBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void FTMSBike::test_case1()
{

}

QTEST_APPLESS_MAIN(FTMSBike)



#include "tst_ftmsbike.moc"


