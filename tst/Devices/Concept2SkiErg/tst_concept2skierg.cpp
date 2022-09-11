#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Concept2SkiErg : public BluetoothDevice
{
    Q_OBJECT

public:
    Concept2SkiErg();
	~Concept2SkiErg();
    

private slots:
    void test_case1();
	
};

Concept2SkiErg::Concept2SkiErg()
{

}

Concept2SkiErg::~Concept2SkiErg()
{

}

void Concept2SkiErg::test_case1()
{

}

QTEST_APPLESS_MAIN(Concept2SkiErg)



#include "tst_concept2skierg.moc"


