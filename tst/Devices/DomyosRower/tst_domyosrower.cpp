#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"
#include "autotest.h"

#include "domyosrower.h"

class DomyosRower : public BluetoothDevice
{
	Q_OBJECT

public:
	DomyosRower();
	~DomyosRower();

    QStringList get_deviceNames() override;
	bool get_isExpectedDevice(bluetoothdevice * detectedDevice) override;
    

private slots:
    void test_case1();
	
};

DomyosRower::DomyosRower()
{

}

DomyosRower::~DomyosRower()
{

}

bool DomyosRower::get_isExpectedDevice(bluetoothdevice * detectedDevice) {
	return dynamic_cast<domyosrower*>(detectedDevice)!=nullptr;	
}

QStringList DomyosRower::get_deviceNames() {
    QStringList result;

    result.append("DOMYOS-ROW");
    result.append("domyos-row");
    result.append("domYos-RoWfjdsfd");

    return result;
}

void DomyosRower::test_case1()
{

}

DECLARE_TEST(DomyosRower)



#include "tst_domyosrower.moc"


