#include <QtTest>

// add necessary includes here

#include "tst_bluetoothdevice.h"

class NautilusTreadmill : public BluetoothDevice
{
    Q_OBJECT

public:
    NautilusTreadmill();
	~NautilusTreadmill();
    

private slots:
    void test_case1();
	
};

NautilusTreadmill::NautilusTreadmill()
{

}

NautilusTreadmill::~NautilusTreadmill()
{

}

void NautilusTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(NautilusTreadmill)



#include "tst_nautilustreadmill.moc"


