#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class MCFBike : public BluetoothDevice
{
    Q_OBJECT

public:
    MCFBike();
	~MCFBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

MCFBike::MCFBike()
{

}

MCFBike::~MCFBike()
{

}

QStringList MCFBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void MCFBike::test_case1()
{

}

QTEST_APPLESS_MAIN(MCFBike)



#include "tst_mcfbike.moc"


