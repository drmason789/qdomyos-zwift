#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class YesoulBike : public BluetoothDevice
{
    Q_OBJECT

public:
    YesoulBike();
	~YesoulBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

YesoulBike::YesoulBike()
{

}

YesoulBike::~YesoulBike()
{

}

QStringList YesoulBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void YesoulBike::test_case1()
{

}

QTEST_APPLESS_MAIN(YesoulBike)



#include "tst_yesoulbike.moc"


