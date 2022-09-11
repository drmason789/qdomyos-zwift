#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SmartRowRower : public BluetoothDevice
{
    Q_OBJECT

public:
    SmartRowRower();
	~SmartRowRower();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

SmartRowRower::SmartRowRower()
{

}

SmartRowRower::~SmartRowRower()
{

}

QStringList SmartRowRower::get_deviceNames() {
	QStringList result;
	return result;
 }

void SmartRowRower::test_case1()
{

}

QTEST_APPLESS_MAIN(SmartRowRower)



#include "tst_smartrowrower.moc"


