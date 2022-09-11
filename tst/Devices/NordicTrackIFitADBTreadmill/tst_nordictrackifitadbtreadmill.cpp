#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class NordicTrackIFitADBTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    NordicTrackIFitADBTreadmill();
	~NordicTrackIFitADBTreadmill();
    

private slots:
    void test_case1();
	
};

NordicTrackIFitADBTreadmill::NordicTrackIFitADBTreadmill()
{

}

NordicTrackIFitADBTreadmill::~NordicTrackIFitADBTreadmill()
{

}

void NordicTrackIFitADBTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(NordicTrackIFitADBTreadmill)



#include "tst_nordictrackifitadbtreadmill.moc"


