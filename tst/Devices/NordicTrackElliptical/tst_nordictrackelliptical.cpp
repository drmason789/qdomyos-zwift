#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class NordicTrackElliptical : public BluetoothDevice
{
    Q_OBJECT

public:
    NordicTrackElliptical();
	~NordicTrackElliptical();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

NordicTrackElliptical::NordicTrackElliptical()
{

}

NordicTrackElliptical::~NordicTrackElliptical()
{

}

QStringList NordicTrackElliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void NordicTrackElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(NordicTrackElliptical)



#include "tst_nordictrackelliptical.moc"


