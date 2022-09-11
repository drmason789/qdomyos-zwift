#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class RenphoBike : public BluetoothDevice
{
    Q_OBJECT

public:
    RenphoBike();
	~RenphoBike();
    

private slots:
    void test_case1();
	
};

RenphoBike::RenphoBike()
{

}

RenphoBike::~RenphoBike()
{

}

void RenphoBike::test_case1()
{

}

QTEST_APPLESS_MAIN(RenphoBike)



#include "tst_renphobike.moc"


