#ifndef DEFAULTLOCKSCREENFUNCTIONS_H
#define DEFAULTLOCKSCREENFUNCTIONS_H

#include "qzlockscreenfunctions.h"

class DefaultLockscreenFunctions : public QZLockscreenFunctions {
public:
    explicit DefaultLockscreenFunctions() {}

    bool updateHeartRate(const double kcal, const double distance, metric &heart, int defaultHeartRate) override { return false;}
    bool updateHeartRate(metric &heart) override {return false;}
    void updateStepCadence(metric& cadence) override {}
    void pelotonBikeUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate) override {}
    void pelotonTreadmillUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate) override {}
};


#endif // DEFAULTLOCKSCREENFUNCTIONS_H
