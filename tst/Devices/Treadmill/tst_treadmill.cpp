#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Treadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    Treadmill();
	~Treadmill();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

Treadmill::Treadmill()
{

}

Treadmill::~Treadmill()
{

}

QStringList Treadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void Treadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(Treadmill)



#include "tst_treadmill.moc"


