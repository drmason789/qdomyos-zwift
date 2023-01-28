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
