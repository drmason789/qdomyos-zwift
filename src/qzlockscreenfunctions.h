#ifndef QZLOCKSCREENFUNCTIONS_H
#define QZLOCKSCREENFUNCTIONS_H

#include "metric.h"

class QZLockscreenFunctions {
protected:
    QZLockscreenFunctions() {}
public:
    virtual ~QZLockscreenFunctions() {}

    /**
     * @brief Updates the kcal and distance on the lockscreen, and gets the heart rate from it.
     * @param kcal
     * @param distance
     * @param heart
     * @param defaultHeartRate
     * @return
     */
    virtual bool updateHeartRate(const double kcal, const double distance, metric &heart, int defaultHeartRate=0)=0;

    /**
     * @brief Get the heart rate from the lockscreen.
     * @param heart
     * @return True if the update occurred, false if not.
     */
    virtual bool updateHeartRate(metric &heart)=0;

    /**
     * @brief Gets the cadence from the lockscreen.
     * @param cadence The metric object to update.
     */
    virtual void updateStepCadence(metric& cadence) = 0;

    /**
     * @brief Indicates if the Peloton workaround is active.
     * @return
     */
    virtual bool isPelotonWorkaroundActive();

    /**
     * @brief Update the crank and heart rate for a bike on the lockscreen if the Peloton workaround is active.
     * @param crankRevolutions
     * @param lastCrankEventTime
     * @param heartRate
     */
    virtual void pelotonBikeUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate)=0;

    /**
     * @brief Update the crank and heart rate for a treadmill on the lockscreen if the Peloton workaround is active.
     * @param crankRevolutions
     * @param lastCrankEventTime
     * @param heartRate
     */
    virtual void pelotonTreadmillUpdateCHR(const double crankRevolutions, const double lastCrankEventTime, const double heartRate)=0;

    static QZLockscreenFunctions * create();
};

#endif // QZLOCKSCREENFUNCTIONS_H
