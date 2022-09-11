#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class StagesBike : public BluetoothDevice
{
    Q_OBJECT

public:
    StagesBike();
	~StagesBike();
    

private slots:
    void test_case1();
	
};

StagesBike::StagesBike()
{

}

StagesBike::~StagesBike()
{

}

void StagesBike::test_case1()
{

}

QTEST_APPLESS_MAIN(StagesBike)



#include "tst_stagesbike.moc"


