#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class FitPlusBike : public BluetoothDevice
{
    Q_OBJECT

public:
    FitPlusBike();
	~FitPlusBike();

	QStringList get_deviceNames() override;
    

private slots:
    void test_case1();
	
};

FitPlusBike::FitPlusBike()
{

}

FitPlusBike::~FitPlusBike()
{

}

QStringList FitPlusBike::get_deviceNames() {
	QStringList result;
	return result;
 }

void FitPlusBike::test_case1()
{

}

QTEST_APPLESS_MAIN(FitPlusBike)



#include "tst_fitplusbike.moc"


