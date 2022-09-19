#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "rower.h"

class Rower : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	QTEST_APPLESS_MAIN(Rower)

	Rower();
	~Rower();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

Rower::Rower()
{

}

Rower::~Rower()
{

}

bool Rower::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<rower*>(detectedDevice)!=nullptr;	
}

QStringList Rower::get_deviceNames() {
	QStringList result;
	return result;
 }

void Rower::test_case1()
{

}

DECLARE_TEST(Rower)



#include "tst_rower.moc"


