#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class ProFormRower : public BluetoothDevice
{
    Q_OBJECT

public:
    ProFormRower();
	~ProFormRower();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

ProFormRower::ProFormRower()
{

}

ProFormRower::~ProFormRower()
{

}

QStringList ProFormRower::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormRower::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormRower)



#include "tst_proformrower.moc"


