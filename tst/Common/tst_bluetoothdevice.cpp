#include "tst_bluetoothdevice.h"

#include "bluetooth.h"

BluetoothDevice::BluetoothDevice()
{
    // Hopefully this will stop the QSettings from interfering with the actual apps settings
    QCoreApplication::setOrganizationName("QDomyos-Zwift");
    QCoreApplication::setApplicationName("QDomyos-Zwift-Tests");
}

BluetoothDevice::~BluetoothDevice()
{

}


void BluetoothDevice::test_deviceDetection()
{
    const QString testUUID = QStringLiteral("b8f79bac-32e5-11ed-a261-0242ac120002");
    QBluetoothUuid uuid{testUUID};

    QStringList names = this->get_deviceNames();

    QVERIFY(names.length()>0);

    /* This is a rough sketch, can't really do this...the bluetooth object automatically starts bluetooth discovery
     all that's needed here is testing name detection and device object creation. */
    bluetooth bt( false);

    for(QString deviceName : names)
    {
        QBluetoothDeviceInfo deviceInfo{uuid, deviceName, 0};

        bt.deviceConnected(deviceInfo);

        bluetoothdevice * detectedDevice = bt.device();

        QVERIFY(detectedDevice!=nullptr);
        QVERIFY(this->get_isExpectedDevice(detectedDevice));
    }


}



//#include "tst_bluetoothdevice.moc"
#include "moc_tst_bluetoothdevice.cpp"
