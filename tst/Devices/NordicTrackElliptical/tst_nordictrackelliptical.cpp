#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class NordicTrackElliptical : public BluetoothDevice
{
    Q_OBJECT

public:
    NordicTrackElliptical();
	~NordicTrackElliptical();
    

private slots:
    void test_case1();
	
};

NordicTrackElliptical::NordicTrackElliptical()
{

}

NordicTrackElliptical::~NordicTrackElliptical()
{

}

void NordicTrackElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(NordicTrackElliptical)



#include "tst_nordictrackelliptical.moc"


