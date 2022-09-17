#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "concept2skierg.h"

class Concept2SkiErg : public BluetoothDevice
{
	Q_OBJECT

public:
	Concept2SkiErg();
	~Concept2SkiErg();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

Concept2SkiErg::Concept2SkiErg()
{

}

Concept2SkiErg::~Concept2SkiErg()
{

}

bool Concept2SkiErg::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<concept2skierg*>(detectedDevice)!=nullptr;	
}

QStringList Concept2SkiErg::get_deviceNames() {
	QStringList result;
	return result;
 }

void Concept2SkiErg::test_case1()
{

}

DECLARE_TEST(Concept2SkiErg)



#include "tst_concept2skierg.moc"


