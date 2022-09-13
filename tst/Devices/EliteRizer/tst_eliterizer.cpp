#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "eliterizer.h"

class EliteRizer : public BluetoothDevice
{
	Q_OBJECT

public:
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

QTEST_APPLESS_MAIN(EliteRizer)



#include "tst_eliterizer.moc"


