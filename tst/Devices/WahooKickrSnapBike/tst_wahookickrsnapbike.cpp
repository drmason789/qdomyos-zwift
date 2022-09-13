#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "wahookickrsnapbike.h"

class WahooKickrSnapBike : public BluetoothDevice
{
	Q_OBJECT

public:
	WahooKickrSnapBike();
	~WahooKickrSnapBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

WahooKickrSnapBike::WahooKickrSnapBike()
{

}

WahooKickrSnapBike::~WahooKickrSnapBike()
{

}

bool WahooKickrSnapBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<wahookickrsnapbike*>(detectedDevice)!=nullptr;	
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


