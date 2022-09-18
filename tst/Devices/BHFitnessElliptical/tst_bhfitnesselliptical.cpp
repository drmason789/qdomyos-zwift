#include <QtTest>
#include "tst_bluetoothdevice.h"
#include "autotest.h"


#include "bhfitnesselliptical.h"

class BHFitnessElliptical : public BluetoothDevice
{
	Q_OBJECT

public:
	BHFitnessElliptical();
	~BHFitnessElliptical();

    QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;

private slots:
    void test_case1();
	
};



BHFitnessElliptical::BHFitnessElliptical()
{

}

BHFitnessElliptical::~BHFitnessElliptical()
{

}

bool BHFitnessElliptical::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<bhfitnesselliptical*>(detectedDevice)!=nullptr;	
}

QStringList BHFitnessElliptical::get_deviceNames() {
    QStringList result;

    result.append("B01_");
    result.append("b01_");
    result.append("b01_1234");
    result.append("B01_exTraChars");

    return result;
}

void BHFitnessElliptical::test_case1()
{

}

DECLARE_TEST(BHFitnessElliptical)

#include "tst_bhfitnesselliptical.moc"


