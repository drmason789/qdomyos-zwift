#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "fitshowtreadmill.h"

class FitshowTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	FitshowTreadmill();
	~FitshowTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

FitshowTreadmill::FitshowTreadmill()
{

}

FitshowTreadmill::~FitshowTreadmill()
{

}

bool FitshowTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<fitshowtreadmill*>(detectedDevice)!=nullptr;	
}

QStringList FitshowTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void FitshowTreadmill::test_case1()
{

}

DECLARE_TEST(FitshowTreadmill)



#include "tst_fitshowtreadmill.moc"


