#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "nautilusbike.h"

class NautilusBike : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(NautilusBike)

	NautilusBike();
	~NautilusBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

NautilusBike::NautilusBike()
{

}

NautilusBike::~NautilusBike()
{

}

bool NautilusBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<nautilusbike*>(detectedDevice)!=nullptr;	
}

QStringList NautilusBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void NautilusBike::test_case1()
{

}

DECLARE_TEST(NautilusBike)



#include "tst_nautilusbike.moc"


