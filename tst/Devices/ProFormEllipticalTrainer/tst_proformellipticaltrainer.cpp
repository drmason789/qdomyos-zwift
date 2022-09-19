#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "proformellipticaltrainer.h"

class ProFormEllipticalTrainer : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(ProFormEllipticalTrainer)

	ProFormEllipticalTrainer();
	~ProFormEllipticalTrainer();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

ProFormEllipticalTrainer::ProFormEllipticalTrainer()
{

}

ProFormEllipticalTrainer::~ProFormEllipticalTrainer()
{

}

bool ProFormEllipticalTrainer::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<proformellipticaltrainer*>(detectedDevice)!=nullptr;	
}

QStringList ProFormEllipticalTrainer::get_deviceNames() {
	QStringList result;
	return result;
 }

void ProFormEllipticalTrainer::test_case1()
{

}

DECLARE_TEST(ProFormEllipticalTrainer)



#include "tst_proformellipticaltrainer.moc"


