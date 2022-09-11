#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SportsPlusBike : public BluetoothDevice
{
    Q_OBJECT

public:
    SportsPlusBike();
	~SportsPlusBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

SportsPlusBike::SportsPlusBike()
{

}

SportsPlusBike::~SportsPlusBike()
{

}

QStringList SportsPlusBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void SportsPlusBike::test_case1()
{

}

QTEST_APPLESS_MAIN(SportsPlusBike)



#include "tst_sportsplusbike.moc"


