#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class ToorxTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    ToorxTreadmill();
	~ToorxTreadmill();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

ToorxTreadmill::ToorxTreadmill()
{

}

ToorxTreadmill::~ToorxTreadmill()
{

}

QStringList ToorxTreadmill::get_deviceNames() {
	QStringList result;
	return result;
 }

void ToorxTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(ToorxTreadmill)



#include "tst_toorxtreadmill.moc"


