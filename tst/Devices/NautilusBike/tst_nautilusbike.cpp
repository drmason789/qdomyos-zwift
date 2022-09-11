#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class NautilusBike : public BluetoothDevice
{
    Q_OBJECT

public:
    NautilusBike();
	~NautilusBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

NautilusBike::NautilusBike()
{

}

NautilusBike::~NautilusBike()
{

}

QStringList NautilusBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void NautilusBike::test_case1()
{

}

QTEST_APPLESS_MAIN(NautilusBike)



#include "tst_nautilusbike.moc"


