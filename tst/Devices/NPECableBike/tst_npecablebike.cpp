#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class NPECableBike : public BluetoothDevice
{
    Q_OBJECT

public:
    NPECableBike();
	~NPECableBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

NPECableBike::NPECableBike()
{

}

NPECableBike::~NPECableBike()
{

}

QStringList NPECableBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void NPECableBike::test_case1()
{

}

QTEST_APPLESS_MAIN(NPECableBike)



#include "tst_npecablebike.moc"


