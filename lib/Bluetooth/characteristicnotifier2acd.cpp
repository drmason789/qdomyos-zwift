#include "characteristicnotifier2acd.h"
#include "Devices/treadmill.h"
#include <qmath.h>

CharacteristicNotifier2ACD::CharacteristicNotifier2ACD(bluetoothdevice *Bike, QObject *parent)
    : CharacteristicNotifier(0x2acd, parent), Bike(Bike) {}

int CharacteristicNotifier2ACD::notify(QByteArray &value) {
    bluetoothdevice::BLUETOOTH_TYPE dt = Bike->deviceType();
    if (dt == bluetoothdevice::TREADMILL || dt == bluetoothdevice::ELLIPTICAL) {
        value.append(0x08);       // Inclination available
        value.append((char)0x01); // heart rate available

        uint16_t normalizeSpeed = (uint16_t)qRound(Bike->currentSpeed().value() * 100);
        char a = (normalizeSpeed >> 8) & 0XFF;
        char b = normalizeSpeed & 0XFF;
        QByteArray speedBytes;
        speedBytes.append(b);
        speedBytes.append(a);
        uint16_t normalizeIncline = 0;
        if (dt == bluetoothdevice::TREADMILL)
            normalizeIncline = (uint32_t)qRound(((treadmill *)Bike)->currentInclination().value() * 10);
        a = (normalizeIncline >> 8) & 0XFF;
        b = normalizeIncline & 0XFF;
        QByteArray inclineBytes;
        inclineBytes.append(b);
        inclineBytes.append(a);
        double ramp = 0;
        if (dt == bluetoothdevice::TREADMILL)
            ramp = qRadiansToDegrees(qAtan(((treadmill *)Bike)->currentInclination().value() / 100));
        int16_t normalizeRamp = (int32_t)qRound(ramp * 10);
        a = (normalizeRamp >> 8) & 0XFF;
        b = normalizeRamp & 0XFF;
        QByteArray rampBytes;
        rampBytes.append(b);
        rampBytes.append(a);

        value.append(speedBytes); // Actual value.

        value.append(inclineBytes); // incline

        value.append(rampBytes); // ramp angle

        value.append(Bike->currentHeart().value()); // current heart rate
        return CN_OK;
    } else
        return CN_INVALID;
}
