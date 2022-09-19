#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "snodebike.h"

class SnodeBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(SnodeBike)

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

DECLARE_TEST(SnodeBike)



#include "tst_snodebike.moc"


