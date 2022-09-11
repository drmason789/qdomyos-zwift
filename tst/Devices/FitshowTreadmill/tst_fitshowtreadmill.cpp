#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FitshowTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    FitshowTreadmill();
	~FitshowTreadmill();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

FitshowTreadmill::FitshowTreadmill()
{

}

FitshowTreadmill::~FitshowTreadmill()
{

}

QStringList FitshowTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void FitshowTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(FitshowTreadmill)



#include "tst_fitshowtreadmill.moc"


