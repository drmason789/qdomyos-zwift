#ifndef CHARACTERISTICNOTIFIER2A53_H
#define CHARACTERISTICNOTIFIER2A53_H

#include "Devices/bluetoothdevice.h"
#include "characteristicnotifier.h"

class CharacteristicNotifier2A53 : public CharacteristicNotifier {
    bluetoothdevice *Bike;

  public:
    explicit CharacteristicNotifier2A53(bluetoothdevice *Bike, QObject *parent = nullptr);
    virtual int notify(QByteArray &out);
};

#endif // CHARACTERISTICNOTIFIER2A53_H
