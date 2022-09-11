#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class ProFormElliptical : public BluetoothDevice
{
    Q_OBJECT

public:
    ProFormElliptical();
	~ProFormElliptical();
    

private slots:
    void test_case1();
	
};

ProFormElliptical::ProFormElliptical()
{

}

ProFormElliptical::~ProFormElliptical()
{

}

void ProFormElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormElliptical)



#include "tst_proformelliptical.moc"


