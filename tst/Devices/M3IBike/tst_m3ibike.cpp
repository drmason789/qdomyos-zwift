#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "m3ibike.h"

class M3IBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(M3IBike)

	M3IBike();
	~M3IBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

M3IBike::M3IBike()
{

}

M3IBike::~M3IBike()
{

}

bool M3IBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<m3ibike*>(detectedDevice)!=nullptr;	
}

QStringList M3IBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void M3IBike::test_case1()
{

}

DECLARE_TEST(M3IBike)



#include "tst_m3ibike.moc"


