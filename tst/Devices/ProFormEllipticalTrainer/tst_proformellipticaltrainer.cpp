#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class ProFormEllipticalTrainer : public BluetoothDevice
{
    Q_OBJECT

public:
    ProFormEllipticalTrainer();
	~ProFormEllipticalTrainer();
    

private slots:
    void test_case1();
	
};

ProFormEllipticalTrainer::ProFormEllipticalTrainer()
{

}

ProFormEllipticalTrainer::~ProFormEllipticalTrainer()
{

}

void ProFormEllipticalTrainer::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormEllipticalTrainer)



#include "tst_proformellipticaltrainer.moc"


