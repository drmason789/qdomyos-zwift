#include "ioslockscreenfunctions.h"
#include "qzsettings.h"
#include <QSettings>

//#define Q_OS_IOS
#ifdef Q_OS_IOS
 #ifndef IO_UNDER_QT
#include "ios/lockscreen.h"
#define IOS_ENABLED 1
#endif
#endif

IOSLockscreenFunctions::IOSLockscreenFunctions() : QZLockscreenFunctions() {

    // prevent instantiation on the wrong platform
#ifndef IOS_ENABLED
    throw "Not supported on this platform";
#endif

    QSettings settings;
    bool cadence = settings.value(QZSettings::bike_cadence_sensor, QZSettings::default_bike_cadence_sensor).toBool();
    bool ios_peloton_workaround = settings.value(QZSettings::ios_peloton_workaround, QZSettings::default_ios_peloton_workaround).toBool();
    if (ios_peloton_workaround && cadence) {
        qDebug() << "ios_peloton_workaround activated!";
#ifdef IOS_ENABLED
        lockscreen::virtualbike_ios();
#endif
        this->pelotonWorkaroundActive = true;

    }
}

bool IOSLockscreenFunctions::isPelotonWorkaroundActive() {
    return this->pelotonWorkaroundActive;
}

bool IOSLockscreenFunctions::updateHeartRate(const double kcal, const double distance, metric &heart, int defaultHeartRate) {

    long appleWatchHeartRate = 0;

#ifdef IOS_ENABLED
    appleWatchHeartRate = lockscreen::heartRate();
    lockscreen::setKcal(kcal);
    lockscreen::setDistance(distance);
#endif

    if (appleWatchHeartRate == 0)
        heart = defaultHeartRate;
    else
        heart = appleWatchHeartRate;

    qDebug() << "Current Heart from Apple Watch: " + QString::number(appleWatchHeartRate);

    //debug("Current Heart from Apple Watch: " + QString::number(appleWatchHeartRate));
    return true;
}

bool IOSLockscreenFunctions::updateHeartRate(metric &heart) {
    long appleWatchHeartRate = 0;

#ifdef IOS_ENABLED
    appleWatchHeartRate = lockscreen::heartRate();
#endif

    heart = appleWatchHeartRate;

    qDebug() << "Current Heart from Apple Watch: " + QString::number(appleWatchHeartRate);

    //debug("Current Heart from Apple Watch: " + QString::number(appleWatchHeartRate));
    return true;
}

void IOSLockscreenFunctions::updateStepCadence(metric &cadence) {
#ifdef IOS_ENABLED
    QSettings settings;
    if (settings.value(QZSettings::power_sensor_name, QZSettings::default_power_sensor_name)
            .toString()
            .startsWith(QStringLiteral("Disabled")))
    {
        long appleWatchCadence = lockscreen::stepCadence();
        cadence = appleWatchCadence;
    }
#endif
}

void IOSLockscreenFunctions::pelotonBikeUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate) {
    if(!this->isPelotonWorkaroundActive())
        return;

#ifdef IOS_ENABLED
    lockscreen::virtualbike_setCadence(crankRevolutions, lastCrankEventTime());
    lockscreen::virtualbike_setHeartRate((uint8_t)heartRate);
#endif
}

void IOSLockscreenFunctions::pelotonTreadmillUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate) {

    if(!this->isPelotonWorkaroundActive())
        return;

#ifdef IOS_ENABLED
    lockscreen::virtualTreadmill_setCadence(currentCrankRevolutions(), lastCrankEventTime());
    lockscreen::virtualTreadmill_setHeartRate((uint8_t)metrics_override_heartrate());
#endif
}
