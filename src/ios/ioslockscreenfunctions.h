#ifndef IOSLOCKSCREENFUNCTIONS_H
#define IOSLOCKSCREENFUNCTIONS_H

#include <qglobal.h>

#include "qzlockscreenfunctions.h"

class IOSLockscreenFunctions : public QZLockscreenFunctions {
private:
    bool pelotonWorkaroundActive = false;
public:
    explicit IOSLockscreenFunctions();

    bool isPelotonWorkaroundActive() override;
    bool updateHeartRate(const double kcal, const double distance, metric &heart, int defaultHeartRate) override;
    bool updateHeartRate(metric &heart) override;
    void updateStepCadence(metric& cadence) override;
    void pelotonBikeUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate) override;
    void pelotonTreadmillUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate) override;
};


#endif // IOSLOCKSCREENFUNCTIONS_H
