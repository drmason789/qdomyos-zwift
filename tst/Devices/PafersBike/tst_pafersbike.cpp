#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "pafersbike.h"

class PafersBike : public BluetoothDevice
{
	Q_OBJECT

public:
	PafersBike();
	~PafersBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

PafersBike::PafersBike()
{

}

PafersBike::~PafersBike()
{

}

bool PafersBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<pafersbike*>(detectedDevice)!=nullptr;	
}

QStringList PafersBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void PafersBike::test_case1()
{

}

QTEST_APPLESS_MAIN(PafersBike)



#include "tst_pafersbike.moc"


