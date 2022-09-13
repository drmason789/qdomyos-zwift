#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "chronobike.h"

class Chronobike : public BluetoothDevice
{
	Q_OBJECT

public:
	Chronobike();
	~Chronobike();

    QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

Chronobike::Chronobike()
{

}

Chronobike::~Chronobike()
{

}

bool Chronobike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<chronobike*>(detectedDevice)!=nullptr;	
}

QStringList Chronobike::get_deviceNames() {
	QStringList result;
	return result;
 }

void Chronobike::test_case1()
{

}

QTEST_APPLESS_MAIN(Chronobike)



#include "tst_chronobike.moc"


