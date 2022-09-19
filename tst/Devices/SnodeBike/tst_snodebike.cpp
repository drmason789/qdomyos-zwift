#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "snodebike.h"

class SnodeBike : public BluetoothDevice
{
	Q_OBJECT

public:
	SnodeBike();
	~SnodeBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

SnodeBike::SnodeBike()
{

}

SnodeBike::~SnodeBike()
{

}

bool SnodeBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<snodebike*>(detectedDevice)!=nullptr;	
}

QStringList SnodeBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void SnodeBike::test_case1()
{

}

QTEST_APPLESS_MAIN(SnodeBike)



#include "tst_snodebike.moc"


