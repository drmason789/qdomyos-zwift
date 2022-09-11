#include "tst_bluetoothdevice.h"



BluetoothDevice::BluetoothDevice()
{

}

BluetoothDevice::~BluetoothDevice()
{

}

void BluetoothDevice::test_deviceDetection()
{
    QStringList names = this->get_deviceNames();

    QVERIFY(names.length()>0);
}



//#include "tst_bluetoothdevice.moc"
#include "moc_tst_bluetoothdevice.cpp"
