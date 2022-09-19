#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "technogymmyruntreadmillrfcomm.h"

class TechnogymMyRunTreadmillRFComm : public BluetoothDevice
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(TechnogymMyRunTreadmillRFComm)

	TechnogymMyRunTreadmillRFComm();
	~TechnogymMyRunTreadmillRFComm();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

TechnogymMyRunTreadmillRFComm::TechnogymMyRunTreadmillRFComm()
{

}

TechnogymMyRunTreadmillRFComm::~TechnogymMyRunTreadmillRFComm()
{

}

bool TechnogymMyRunTreadmillRFComm::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<technogymmyruntreadmillrfcomm*>(detectedDevice)!=nullptr;	
}

QStringList TechnogymMyRunTreadmillRFComm::get_deviceNames() {
	QStringList result;
	return result;
 }

void TechnogymMyRunTreadmillRFComm::test_case1()
{

}

DECLARE_TEST(TechnogymMyRunTreadmillRFComm)



#include "tst_technogymmyruntreadmillrfcomm.moc"


