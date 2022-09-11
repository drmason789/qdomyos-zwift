#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class TechnoGymMyRunTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    TechnoGymMyRunTreadmill();
	~TechnoGymMyRunTreadmill();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

TechnoGymMyRunTreadmill::TechnoGymMyRunTreadmill()
{

}

TechnoGymMyRunTreadmill::~TechnoGymMyRunTreadmill()
{

}

QStringList TechnoGymMyRunTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void TechnoGymMyRunTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(TechnoGymMyRunTreadmill)



#include "tst_technogymmyruntreadmill.moc"


