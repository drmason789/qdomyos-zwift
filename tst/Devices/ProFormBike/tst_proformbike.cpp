#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class ProFormBike : public BluetoothDevice
{
    Q_OBJECT

public:
    ProFormBike();
	~ProFormBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

ProFormBike::ProFormBike()
{

}

ProFormBike::~ProFormBike()
{

}

QStringList ProFormBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormBike::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormBike)



#include "tst_proformbike.moc"


