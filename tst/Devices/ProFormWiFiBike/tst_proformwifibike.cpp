#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class ProFormWiFiBike : public BluetoothDevice
{
    Q_OBJECT

public:
    ProFormWiFiBike();
	~ProFormWiFiBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

ProFormWiFiBike::ProFormWiFiBike()
{

}

ProFormWiFiBike::~ProFormWiFiBike()
{

}

QStringList ProFormWiFiBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormWiFiBike::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormWiFiBike)



#include "tst_proformwifibike.moc"


