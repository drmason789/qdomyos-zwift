#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class YesoulBike : public BluetoothDevice
{
    Q_OBJECT

public:
    YesoulBike();
	~YesoulBike();
    

private slots:
    void test_case1();
	
};

YesoulBike::YesoulBike()
{

}

YesoulBike::~YesoulBike()
{

}

void YesoulBike::test_case1()
{

}

QTEST_APPLESS_MAIN(YesoulBike)



#include "tst_yesoulbike.moc"


