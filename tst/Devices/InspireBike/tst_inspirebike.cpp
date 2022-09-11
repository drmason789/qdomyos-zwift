#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class InspireBike : public BluetoothDevice
{
    Q_OBJECT

public:
    InspireBike();
	~InspireBike();
    

private slots:
    void test_case1();
	
};

InspireBike::InspireBike()
{

}

InspireBike::~InspireBike()
{

}

void InspireBike::test_case1()
{

}

QTEST_APPLESS_MAIN(InspireBike)



#include "tst_inspirebike.moc"


