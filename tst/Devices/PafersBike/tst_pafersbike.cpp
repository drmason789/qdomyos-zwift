#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class PafersBike : public BluetoothDevice
{
    Q_OBJECT

public:
    PafersBike();
	~PafersBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

PafersBike::PafersBike()
{

}

PafersBike::~PafersBike()
{

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


