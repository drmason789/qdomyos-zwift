#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Rower : public BluetoothDevice
{
    Q_OBJECT

public:
    Rower();
	~Rower();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

Rower::Rower()
{

}

Rower::~Rower()
{

}

QStringList Rower::get_deviceNames() {
	QStringList result;
	return result;
 }

void Rower::test_case1()
{

}

QTEST_APPLESS_MAIN(Rower)



#include "tst_rower.moc"


