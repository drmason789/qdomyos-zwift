#ifndef QZLOCKSCREEN_H
#define QZLOCKSCREEN_H

#include "metric.h"

class QZLockscreenFunctions {
protected:
    QZLockscreenFunctions() {}
public:
    virtual ~QZLockscreenFunctions() {}

    virtual bool updateHeartRate(const double kcal, const double distance, metric &heart, int defaultHeartRate=0)=0;
    virtual bool updateHeartRate(metric &heart)=0;
    virtual void updateStepCadence(metric& cadence) = 0;

    virtual bool isPelotonWorkaroundActive();
    virtual void pelotonBikeUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate)=0;
    virtual void pelotonTreadmillUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate)=0;

    static QZLockscreenFunctions * create();
};

#endif // QZLOCKSCREEN_H
