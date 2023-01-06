#ifndef DIRCONMANAGER_H
#define DIRCONMANAGER_H

#include "bluetoothdevice.h"
#include "Bluetooth/characteristicnotifier2a37.h"
#include "Bluetooth/characteristicnotifier2a53.h"
#include "Bluetooth/characteristicnotifier2a5b.h"
#include "Bluetooth/characteristicnotifier2a63.h"
#include "Bluetooth/characteristicnotifier2acc.h"
#include "Bluetooth/characteristicnotifier2acd.h"
#include "Bluetooth/characteristicnotifier2ad2.h"
#include "Bluetooth/characteristicnotifier2ad9.h"
#include "Bluetooth/characteristicwriteprocessor2ad9.h"
#include "Bluetooth/characteristicwriteprocessore005.h"
#include "dirconpacket.h"
#include "dirconprocessor.h"
#include <QObject>

#define DM_CHAR_NOTIF_OP(OP, P1, P2, P3)                                                                               \
    OP(2AD2, P1, P2, P3)                                                                                               \
    OP(2A63, P1, P2, P3)                                                                                               \
    OP(2A37, P1, P2, P3) OP(2A5B, P1, P2, P3) OP(2A53, P1, P2, P3) OP(2ACD, P1, P2, P3) OP(2ACC, P1, P2, P3)           \
        OP(2AD9, P1, P2, P3)

#define DM_CHAR_NOTIF_DEFINE_OP(UUID, P1, P2, P3) CharacteristicNotifier##UUID *notif##UUID = 0;

class DirconManager : public QObject {
    Q_OBJECT
    QTimer bikeTimer;
    CharacteristicWriteProcessor2AD9 *writeP2AD9 = 0;
    CharacteristicWriteProcessorE005 *writePE005 = 0;
    DM_CHAR_NOTIF_OP(DM_CHAR_NOTIF_DEFINE_OP, 0, 0, 0)
    QList<DirconProcessor *> processors;
    static QString getMacAddress();

  public:
    explicit DirconManager(bluetoothdevice *t, uint8_t bikeResistanceOffset = 4, double bikeResistanceGain = 1.0,
                           QObject *parent = nullptr);
  private slots:
    void bikeProvider();
  signals:
    void changeInclination(double grade, double percentage);
    void ftmsCharacteristicChanged(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue);
};

#endif // DIRCOMMANAGER_H
