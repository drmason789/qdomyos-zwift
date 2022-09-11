#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class StagesBike : public BluetoothDevice
{
    Q_OBJECT

public:
    StagesBike();
	~StagesBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

StagesBike::StagesBike()
{

}

StagesBike::~StagesBike()
{

}

QStringList StagesBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void StagesBike::test_case1()
{

}

QTEST_APPLESS_MAIN(StagesBike)



#include "tst_stagesbike.moc"


