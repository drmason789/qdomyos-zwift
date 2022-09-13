#include <QtTest>
#include <QStringList>

// add necessary includes here
#include "activiotreadmill.h"
#include "tst_bluetoothdevice.h"

class ActivioTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	ActivioTreadmill();
	~ActivioTreadmill();

    QStringList get_deviceNames() override;
    bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;

private slots:
    void test_case1();
	
};

ActivioTreadmill::ActivioTreadmill()
{

}

ActivioTreadmill::~ActivioTreadmill()
{

}

bool ActivioTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<activiotreadmill*>(detectedDevice)!=nullptr;	
}

QStringList ActivioTreadmill::get_deviceNames() {
    QStringList result;

    result.append("RUNNERT");
    result.append("runnert");
    result.append("ruNnerT");
    result.append("runnERt12314");

    return result;
}


void ActivioTreadmill::test_case1()
{
    activiotreadmill * treadmill = new activiotreadmill();
    delete treadmill;
}

QTEST_APPLESS_MAIN(ActivioTreadmill)

#include "tst_activiotreadmill.moc"


