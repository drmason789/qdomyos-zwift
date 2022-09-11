#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class WahooKickrSnapBike : public BluetoothDevice
{
    Q_OBJECT

public:
    WahooKickrSnapBike();
	~WahooKickrSnapBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

WahooKickrSnapBike::WahooKickrSnapBike()
{

}

WahooKickrSnapBike::~WahooKickrSnapBike()
{

}

QStringList WahooKickrSnapBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void WahooKickrSnapBike::test_case1()
{

}

QTEST_APPLESS_MAIN(WahooKickrSnapBike)



#include "tst_wahookickrsnapbike.moc"


