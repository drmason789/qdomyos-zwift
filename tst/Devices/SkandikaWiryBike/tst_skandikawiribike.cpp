#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SkandikaWiryBike : public BluetoothDevice
{
    Q_OBJECT

public:
    SkandikaWiryBike();
	~SkandikaWiryBike();
    

private slots:
    void test_case1();
	
};

SkandikaWiryBike::SkandikaWiryBike()
{

}

SkandikaWiryBike::~SkandikaWiryBike()
{

}

void SkandikaWiryBike::test_case1()
{

}

QTEST_APPLESS_MAIN(SkandikaWiryBike)



#include "tst_skandikawiribike.moc"


