#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class M3IBike : public BluetoothDevice
{
    Q_OBJECT

public:
    M3IBike();
	~M3IBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

M3IBike::M3IBike()
{

}

M3IBike::~M3IBike()
{

}

QStringList M3IBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void M3IBike::test_case1()
{

}

QTEST_APPLESS_MAIN(M3IBike)



#include "tst_m3ibike.moc"


