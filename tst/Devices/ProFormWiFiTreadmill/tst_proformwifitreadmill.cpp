#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class ProFormWiFiTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    ProFormWiFiTreadmill();
	~ProFormWiFiTreadmill();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

ProFormWiFiTreadmill::ProFormWiFiTreadmill()
{

}

ProFormWiFiTreadmill::~ProFormWiFiTreadmill()
{

}

QStringList ProFormWiFiTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormWiFiTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormWiFiTreadmill)



#include "tst_proformwifitreadmill.moc"


