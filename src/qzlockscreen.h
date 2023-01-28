#ifndef QZLOCKSCREEN_H
#define QZLOCKSCREEN_H

#include "metric.h"

class qzlockscreen
{
 protected:
    qzlockscreen();
public:

    static bool UpdateHeartRate(const double kcal, const double distance, metric& heart,  int defaultHeartRate=0);
    static bool UpdateHeartRate(metric& heart);

    virtual void virtualbike_ios() =0;


    static bool pelotonWorkaround(qzlockscreen **h);

    void pelotonUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate){
#ifdef Q_OS_IOS
#ifndef IO_UNDER_QT
    bool cadence =
        settings.value(QZSettings::bike_cadence_sensor, QZSettings::default_bike_cadence_sensor).toBool();
    bool ios_peloton_workaround =
        settings.value(QZSettings::ios_peloton_workaround, QZSettings::default_ios_peloton_workaround).toBool();
    if (ios_peloton_workaround && cadence) {
        h->virtualbike_setCadence(crankRevolutions, lastCrankEventTime());
        h->virtualbike_setHeartRate((uint8_t)heartRate);
    }
#endif
#endif
    }

    static void updateStepCadence(metric& cadence) {
#ifdef Q_OS_IOS
#ifndef IO_UNDER_QT
        QSettings settings;
        if (settings.value(QZSettings::power_sensor_name, QZSettings::default_power_sensor_name)
                .toString()
                .startsWith(QStringLiteral("Disabled")))
        {
            lockscreen h;
            long appleWatchCadence = h.stepCadence();
            cadence = appleWatchCadence;
        }
#endif
#endif
    }

    static qzlockscreen * create() {
        throw "Not implemented";
    }
};

#endif // QZLOCKSCREEN_H
