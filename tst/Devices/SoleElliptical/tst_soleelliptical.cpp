#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SoleElliptical : public BluetoothDevice
{
    Q_OBJECT

public:
    SoleElliptical();
	~SoleElliptical();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

SoleElliptical::SoleElliptical()
{

}

SoleElliptical::~SoleElliptical()
{

}

QStringList SoleElliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void SoleElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(SoleElliptical)



#include "tst_soleelliptical.moc"


