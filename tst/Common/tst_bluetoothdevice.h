#ifndef TST_BLUETOOTHDEVICE_H
#define TST_BLUETOOTHDEVICE_H


#include <QtTest>
#include <QString>

// add necessary includes here

class BluetoothDevice : public QObject
{
    Q_OBJECT

public:
    BluetoothDevice();
    ~BluetoothDevice();

    /**
     * @brief Gets a list of the advertised bluetooth device names that should be recognised as the tested device object.
     */
    virtual QStringList get_deviceNames() { throw std::exception(); }

private slots:
    void test_deviceDetection();

};

#endif // TST_BLUETOOTHDEVICE_H
