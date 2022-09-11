#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class HeartRateBelt : public BluetoothDevice
{
    Q_OBJECT

public:
    HeartRateBelt();
	~HeartRateBelt();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

HeartRateBelt::HeartRateBelt()
{

}

HeartRateBelt::~HeartRateBelt()
{

}

QStringList HeartRateBelt::get_deviceNames() {
	QStringList result;
	return result;
 }

void HeartRateBelt::test_case1()
{

}

QTEST_APPLESS_MAIN(HeartRateBelt)



#include "tst_heartratebelt.moc"


