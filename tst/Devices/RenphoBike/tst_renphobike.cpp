#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "renphobike.h"

class RenphoBike : public BluetoothDevice
{
	Q_OBJECT

public:
	RenphoBike();
	~RenphoBike();

	QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

RenphoBike::RenphoBike()
{

}

RenphoBike::~RenphoBike()
{

}

bool RenphoBike::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<renphobike*>(detectedDevice)!=nullptr;	
}

QStringList RenphoBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void RenphoBike::test_case1()
{

}

DECLARE_TEST(RenphoBike)



#include "tst_renphobike.moc"


