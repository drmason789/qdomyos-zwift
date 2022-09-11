#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class SmartSpin2k : public BluetoothDevice
{
    Q_OBJECT

public:
    SmartSpin2k();
	~SmartSpin2k();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

SmartSpin2k::SmartSpin2k()
{

}

SmartSpin2k::~SmartSpin2k()
{

}

QStringList SmartSpin2k::get_deviceNames() {
	QStringList result;
	return result;
 }

void SmartSpin2k::test_case1()
{

}

QTEST_APPLESS_MAIN(SmartSpin2k)



#include "tst_smartspin2k.moc"


