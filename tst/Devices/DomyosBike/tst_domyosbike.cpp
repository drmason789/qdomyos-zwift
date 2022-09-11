#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class DomyosBike : public BluetoothDevice
{
    Q_OBJECT

public:
    DomyosBike();
	~DomyosBike();
    

private slots:
    void test_case1();
	
};

DomyosBike::DomyosBike()
{

}

DomyosBike::~DomyosBike()
{

}

void DomyosBike::test_case1()
{

}

QTEST_APPLESS_MAIN(DomyosBike)



#include "tst_domyosbike.moc"


