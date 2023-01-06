#ifndef CHARACTERISTICNOTIFIER2AD2_H
#define CHARACTERISTICNOTIFIER2AD2_H

#include "Devices/bluetoothdevice.h"
#include "characteristicnotifier.h"

class CharacteristicNotifier2AD2 : public CharacteristicNotifier {
    bluetoothdevice *Bike;

  public:
    explicit CharacteristicNotifier2AD2(bluetoothdevice *Bike, QObject *parent = nullptr);
    virtual int notify(QByteArray &out);
};

#endif // CHARACTERISTICNOTIFIER2AD2_H
