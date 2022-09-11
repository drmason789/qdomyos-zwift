#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class WahooKickrSnapBike : public BluetoothDevice
{
    Q_OBJECT

public:
    WahooKickrSnapBike();
	~WahooKickrSnapBike();
    

private slots:
    void test_case1();
	
};

WahooKickrSnapBike::WahooKickrSnapBike()
{

}

WahooKickrSnapBike::~WahooKickrSnapBike()
{

}

void WahooKickrSnapBike::test_case1()
{

}

QTEST_APPLESS_MAIN(WahooKickrSnapBike)



#include "tst_wahookickrsnapbike.moc"


