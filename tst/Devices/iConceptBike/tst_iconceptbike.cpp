#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class iConceptBike : public BluetoothDevice
{
    Q_OBJECT

public:
    iConceptBike();
	~iConceptBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

iConceptBike::iConceptBike()
{

}

iConceptBike::~iConceptBike()
{

}

QStringList iConceptBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void iConceptBike::test_case1()
{

}

QTEST_APPLESS_MAIN(iConceptBike)



#include "tst_iconceptbike.moc"


