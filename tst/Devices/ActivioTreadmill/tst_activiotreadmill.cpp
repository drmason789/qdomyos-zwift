#include <QtTest>
#include <QStringList>

// add necessary includes here
#include "activiotreadmill.h"
#include "tst_bluetoothdevice.h"
#include "autotest.h"

class ActivioTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(ActivioTreadmill)

	ActivioTreadmill();
    ~ActivioTreadmill();

    QStringList get_deviceNames() override;
    bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;

private slots:
    void test_case1();

};

DECLARE_TEST(ActivioTreadmill)

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

#include "tst_activiotreadmill.moc"


