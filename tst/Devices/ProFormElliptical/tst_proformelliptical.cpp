#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

#include "proformelliptical.h"

class ProFormElliptical : public BluetoothDevice
{
	Q_OBJECT

public:
	ProFormElliptical();
	~ProFormElliptical();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

ProFormElliptical::ProFormElliptical()
{

}

ProFormElliptical::~ProFormElliptical()
{

}

bool ProFormElliptical::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<proformelliptical*>(detectedDevice)!=nullptr;	
}

QStringList ProFormElliptical::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormElliptical)



#include "tst_proformelliptical.moc"


