#ifndef SKANDIKAWIRIBIKE_H
#define SKANDIKAWIRIBIKE_H

#include <QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/qlowenergyadvertisingdata.h>
#include <QtBluetooth/qlowenergyadvertisingparameters.h>
#include <QtBluetooth/qlowenergycharacteristic.h>
#include <QtBluetooth/qlowenergycharacteristicdata.h>
#include <QtBluetooth/qlowenergycontroller.h>
#include <QtBluetooth/qlowenergydescriptordata.h>
#include <QtBluetooth/qlowenergyservice.h>
#include <QtBluetooth/qlowenergyservicedata.h>
#include <QtCore/qbytearray.h>

#ifndef Q_OS_ANDROID
#include <QtCore/qcoreapplication.h>
#else
#include <QtGui/qguiapplication.h>
#endif
#include <QtCore/qlist.h>
#include <QtCore/qmutex.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qtimer.h>

#include <QDateTime>
#include <QObject>
#include <QString>

#include "bike.h"
#include "virtualbike.h"

class skandikawiribike : public bike {
    Q_OBJECT
  public:
    skandikawiribike(bool noWriteResistance, bool noHeartService, uint8_t bikeResistanceOffset,
                     double bikeResistanceGain);
    ~skandikawiribike();
    bool connected();

    void *VirtualBike();
    void *VirtualDevice();

  private:
    double GetSpeedFromPacket(const QByteArray &packet);
    double GetInclinationFromPacket(QByteArray packet);
    double GetKcalFromPacket(const QByteArray &packet);
    double GetDistanceFromPacket(QByteArray packet);
    double GetWattFromPacket(const QByteArray &packet);
    double GetCadenceFromPacket(const QByteArray &packet);
    char *itoa(int num, char *buffer, int base);
    uint8_t convertHexToDec(uint8_t a);
    void btinit();
    void writeCharacteristic(uint8_t *data, uint8_t data_len, const QString &info, bool disable_log = false,
                             bool wait_for_response = false);
    void startDiscover();
    uint16_t watts();

    QTimer *refresh;
    virtualbike *virtualBike = nullptr;

    QLowEnergyService *gattCommunicationChannelService = nullptr;
    QLowEnergyCharacteristic gattNotify1Characteristic;
    QLowEnergyCharacteristic gattWriteCharacteristic;

    bool initDone = false;
    bool initRequest = false;
    uint8_t bikeResistanceOffset = 4;
    double bikeResistanceGain = 1.0;
    uint8_t sec1Update = 0;
    QByteArray lastPacket;
    QDateTime lastRefreshCharacteristicChanged = QDateTime::currentDateTime();
    
    uint16_t m_watts = 0;

    bool noWriteResistance = false;
    bool noHeartService = false;

  signals:
    void disconnected();
    void debug(QString string);

  public slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &device);

  private slots:

    void characteristicChanged(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue);
    void characteristicWritten(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue);
    void descriptorWritten(const QLowEnergyDescriptor &descriptor, const QByteArray &newValue);
    void stateChanged(QLowEnergyService::ServiceState state);
    void controllerStateChanged(QLowEnergyController::ControllerState state);

    void serviceDiscovered(const QBluetoothUuid &gatt);
    void serviceScanDone(void);
    void update();
    void error(QLowEnergyController::Error err);
    void errorService(QLowEnergyService::ServiceError);
};

#endif // SKANDIKAWIRIBIKE_H