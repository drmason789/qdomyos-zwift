#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Chronobike : public BluetoothDevice
{
    Q_OBJECT

public:
    Chronobike();
	~Chronobike();
    

private slots:
    void test_case1();
	
};

Chronobike::Chronobike()
{

}

Chronobike::~Chronobike()
{

}

void Chronobike::test_case1()
{

}

QTEST_APPLESS_MAIN(Chronobike)



#include "tst_chronobike.moc"


