#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SportsPlusBike : public BluetoothDevice
{
    Q_OBJECT

public:
    SportsPlusBike();
	~SportsPlusBike();
    

private slots:
    void test_case1();
	
};

SportsPlusBike::SportsPlusBike()
{

}

SportsPlusBike::~SportsPlusBike()
{

}

void SportsPlusBike::test_case1()
{

}

QTEST_APPLESS_MAIN(SportsPlusBike)



#include "tst_sportsplusbike.moc"


