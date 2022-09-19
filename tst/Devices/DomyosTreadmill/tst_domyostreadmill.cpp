#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "domyostreadmill.h"

class DomyosTreadmill : public BluetoothDevice
{
	Q_OBJECT

public:
	DomyosTreadmill();
	~DomyosTreadmill();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

DomyosTreadmill::DomyosTreadmill()
{

}

DomyosTreadmill::~DomyosTreadmill()
{

}

bool DomyosTreadmill::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<domyostreadmill*>(detectedDevice)!=nullptr;	
}

QStringList DomyosTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void DomyosTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(DomyosTreadmill)



#include "tst_domyostreadmill.moc"


