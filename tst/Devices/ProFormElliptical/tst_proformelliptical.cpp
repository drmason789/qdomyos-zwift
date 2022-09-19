#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "proformelliptical.h"

class ProFormElliptical : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(ProFormElliptical)

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

DECLARE_TEST(ProFormElliptical)



#include "tst_proformelliptical.moc"


