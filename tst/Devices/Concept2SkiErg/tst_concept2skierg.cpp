#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Concept2SkiErg : public BluetoothDevice
{
    Q_OBJECT

public:
    Concept2SkiErg();
	~Concept2SkiErg();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

Concept2SkiErg::Concept2SkiErg()
{

}

Concept2SkiErg::~Concept2SkiErg()
{

}

QStringList Concept2SkiErg::get_deviceNames() {
	QStringList result;
	return result;
 }

void Concept2SkiErg::test_case1()
{

}

QTEST_APPLESS_MAIN(Concept2SkiErg)



#include "tst_concept2skierg.moc"


