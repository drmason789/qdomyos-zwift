#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "elitesterzosmart.h"

class EliteSterzoSmart : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(EliteSterzoSmart)

	EliteSterzoSmart();
	~EliteSterzoSmart();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

EliteSterzoSmart::EliteSterzoSmart()
{

}

EliteSterzoSmart::~EliteSterzoSmart()
{

}

bool EliteSterzoSmart::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<elitesterzosmart*>(detectedDevice)!=nullptr;	
}

QStringList EliteSterzoSmart::get_deviceNames() {
	QStringList result;
	return result;
 }

void EliteSterzoSmart::test_case1()
{

}

DECLARE_TEST(EliteSterzoSmart)



#include "tst_elitesterzosmart.moc"


