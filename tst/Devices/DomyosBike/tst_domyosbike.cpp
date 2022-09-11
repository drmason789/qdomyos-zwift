#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class DomyosBike : public BluetoothDevice
{
    Q_OBJECT

public:
    DomyosBike();
	~DomyosBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

DomyosBike::DomyosBike()
{

}

DomyosBike::~DomyosBike()
{

}

QStringList DomyosBike::get_deviceNames() {
	QStringList result;

    // at time of typeing this, check in bluetooth.cs was case sensitive
    result.append("Domyos-Bike");
    result.append("Domyos-BikeXYZ");
	return result;
 }

void DomyosBike::test_case1()
{

}

QTEST_APPLESS_MAIN(DomyosBike)



#include "tst_domyosbike.moc"


