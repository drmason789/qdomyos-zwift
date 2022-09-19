#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "eliterizer.h"

class EliteRizer : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(EliteRizer)

	EliteRizer();
	~EliteRizer();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

EliteRizer::EliteRizer()
{

}

EliteRizer::~EliteRizer()
{

}

bool EliteRizer::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<eliterizer*>(detectedDevice)!=nullptr;	
}

QStringList EliteRizer::get_deviceNames() {
	QStringList result;
	return result;
 }

void EliteRizer::test_case1()
{

}

DECLARE_TEST(EliteRizer)



#include "tst_eliterizer.moc"


