#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class CSCBike : public BluetoothDevice
{
    Q_OBJECT

public:
    CSCBike();
	~CSCBike();
    

private slots:
    void test_case1();
	
};

CSCBike::CSCBike()
{

}

CSCBike::~CSCBike()
{

}

void CSCBike::test_case1()
{

}

QTEST_APPLESS_MAIN(CSCBike)



#include "tst_cscbike.moc"


