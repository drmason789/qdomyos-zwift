#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Bowflex216Treadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    Bowflex216Treadmill();
	~Bowflex216Treadmill();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

Bowflex216Treadmill::Bowflex216Treadmill()
{

}

Bowflex216Treadmill::~Bowflex216Treadmill()
{

}

QStringList Bowflex216Treadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void Bowflex216Treadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(Bowflex216Treadmill)

#include "tst_bowflex216treadmill.moc"
