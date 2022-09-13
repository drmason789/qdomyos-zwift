#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "fitmetriafanfit.h"

class FitmetriaFanFit : public BluetoothDevice
{
	Q_OBJECT

public:
	FitmetriaFanFit();
	~FitmetriaFanFit();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

FitmetriaFanFit::FitmetriaFanFit()
{

}

FitmetriaFanFit::~FitmetriaFanFit()
{

}

bool FitmetriaFanFit::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<fitmetriafanfit*>(detectedDevice)!=nullptr;	
}

QStringList FitmetriaFanFit::get_deviceNames() {
	QStringList result;
	return result;
 }

void FitmetriaFanFit::test_case1()
{

}

QTEST_APPLESS_MAIN(FitmetriaFanFit)



#include "tst_fitmetria_fanfit.moc"


