#include <QtTest>
#include "tst_bluetoothdevice.h"


class BHFitnessElliptical : public BluetoothDevice
{
    Q_OBJECT

public:
    BHFitnessElliptical();
	~BHFitnessElliptical();
    

    QStringList get_DeviceNames() override;

private slots:
    void test_case1();
	
};

BHFitnessElliptical::BHFitnessElliptical()
{

}

BHFitnessElliptical::~BHFitnessElliptical()
{

}

QStringList BHFitnessElliptical::get_DeviceNames() {
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

QTEST_APPLESS_MAIN(BHFitnessElliptical)

#include "tst_bhfitnesselliptical.moc"


