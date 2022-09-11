#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class EliteSterzoSmart : public BluetoothDevice
{
    Q_OBJECT

public:
    EliteSterzoSmart();
	~EliteSterzoSmart();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

EliteSterzoSmart::EliteSterzoSmart()
{

}

EliteSterzoSmart::~EliteSterzoSmart()
{

}

QStringList EliteSterzoSmart::get_deviceNames() {
	QStringList result;
	return result;
 }

void EliteSterzoSmart::test_case1()
{

}

QTEST_APPLESS_MAIN(EliteSterzoSmart)



#include "tst_elitesterzosmart.moc"


