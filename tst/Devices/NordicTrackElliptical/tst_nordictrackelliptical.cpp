#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "nordictrackelliptical.h"

class NordicTrackElliptical : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(NordicTrackElliptical)

	NordicTrackElliptical();
	~NordicTrackElliptical();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

NordicTrackElliptical::NordicTrackElliptical()
{

}

NordicTrackElliptical::~NordicTrackElliptical()
{

}

bool NordicTrackElliptical::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<nordictrackelliptical*>(detectedDevice)!=nullptr;	
}

QStringList NordicTrackElliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void NordicTrackElliptical::test_case1()
{

}

DECLARE_TEST(NordicTrackElliptical)



#include "tst_nordictrackelliptical.moc"


