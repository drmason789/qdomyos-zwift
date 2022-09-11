#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class HorizonTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    HorizonTreadmill();
	~HorizonTreadmill();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

HorizonTreadmill::HorizonTreadmill()
{

}

HorizonTreadmill::~HorizonTreadmill()
{

}

QStringList HorizonTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void HorizonTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(HorizonTreadmill)



#include "tst_horizontreadmill.moc"


