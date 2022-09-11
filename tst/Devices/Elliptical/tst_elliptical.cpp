#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class Elliptical : public BluetoothDevice
{
    Q_OBJECT

public:
    Elliptical();
	~Elliptical();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

Elliptical::Elliptical()
{

}

Elliptical::~Elliptical()
{

}

QStringList Elliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void Elliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(Elliptical)



#include "tst_elliptical.moc"


