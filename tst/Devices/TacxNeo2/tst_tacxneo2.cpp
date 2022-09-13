#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "tacxneo2.h"

class TacxNeo2 : public BluetoothDevice
{
	Q_OBJECT

public:
	TacxNeo2();
	~TacxNeo2();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

TacxNeo2::TacxNeo2()
{

}

TacxNeo2::~TacxNeo2()
{

}

bool TacxNeo2::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<tacxneo2*>(detectedDevice)!=nullptr;	
}

QStringList TacxNeo2::get_deviceNames() {
	QStringList result;
	return result;
 }

void TacxNeo2::test_case1()
{

}

QTEST_APPLESS_MAIN(TacxNeo2)



#include "tst_tacxneo2.moc"


