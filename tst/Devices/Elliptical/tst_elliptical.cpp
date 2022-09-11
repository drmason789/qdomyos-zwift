#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Elliptical : public BluetoothDevice
{
    Q_OBJECT

public:
    Elliptical();
	~Elliptical();
    

private slots:
    void test_case1();
	
};

Elliptical::Elliptical()
{

}

Elliptical::~Elliptical()
{

}

void Elliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(Elliptical)



#include "tst_elliptical.moc"


