#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class DomyosElliptical : public BluetoothDevice
{
    Q_OBJECT

public:
    DomyosElliptical();
	~DomyosElliptical();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

DomyosElliptical::DomyosElliptical()
{

}

DomyosElliptical::~DomyosElliptical()
{

}

QStringList DomyosElliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void DomyosElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(DomyosElliptical)



#include "tst_domyoselliptical.moc"


