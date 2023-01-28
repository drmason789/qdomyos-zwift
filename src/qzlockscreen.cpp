#include "qzlockscreen.h"

qzlockscreen::qzlockscreen()
{

}

bool qzlockscreen::UpdateHeartRate(const double kcal, const double distance, metric &heart, int defaultHeartRate){

#ifdef Q_OS_IOS
#ifndef IO_UNDER_QT

    lockscreen h;
    long appleWatchHeartRate = h.heartRate();
    h.setKcal(kcal);
    h.setDistance(distance);

    if (appleWatchHeartRate == 0)
        heart = defaultHeartRate;
    else
        heart = appleWatchHeartRate;

    debug("Current Heart from Apple Watch: " + QString::number(appleWatchHeartRate));
return true;
#endif
#endif
return false;
}

bool qzlockscreen::UpdateHeartRate(metric &heart){
#ifdef Q_OS_IOS
#ifndef IO_UNDER_QT
    lockscreen h;
    long appleWatchHeartRate = h.heartRate();
    heart = appleWatchHeartRate;
    debug("Current Heart from Apple Watch: " + QString::number(appleWatchHeartRate));
    return true;
#endif
#endif
    return false;
}

bool qzlockscreen::pelotonWorkaround(qzlockscreen **h) {

#ifdef Q_OS_IOS
#ifndef IO_UNDER_QT
    QSettings settings;
    bool cadence =
            settings.value(QZSettings::bike_cadence_sensor, QZSettings::default_bike_cadence_sensor).toBool();
    bool ios_peloton_workaround = settings.value(QZSettings::ios_peloton_workaround, QZSettings::default_ios_peloton_workaround).toBool();
    if (ios_peloton_workaround && cadence) {
        qDebug() << "ios_peloton_workaround activated!";
        h = new lockscreen();
        h->virtualbike_ios();
        return true;
    }
#endif
#endif
    return false;
}
