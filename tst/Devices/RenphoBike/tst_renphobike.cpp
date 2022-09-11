#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class RenphoBike : public BluetoothDevice
{
    Q_OBJECT

public:
    RenphoBike();
	~RenphoBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

RenphoBike::RenphoBike()
{

}

RenphoBike::~RenphoBike()
{

}

QStringList RenphoBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void RenphoBike::test_case1()
{

}

QTEST_APPLESS_MAIN(RenphoBike)



#include "tst_renphobike.moc"


