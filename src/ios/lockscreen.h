#ifndef LOCKSCREEN_H
#define LOCKSCREEN_H

class lockscreen {
  public:
    static void setTimerDisabled();
    static void request();
    static long heartRate();
    static long stepCadence();
    static void setKcal(double kcal);
    static void setDistance(double distance);

    // virtualbike
    static void virtualbike_ios();
    static void virtualbike_setHeartRate(unsigned char heartRate);
    static void virtualbike_setCadence(unsigned short crankRevolutions, unsigned short lastCrankEventTime);

    static void virtualbike_zwift_ios();
    static double virtualbike_getCurrentSlope();
    static double virtualbike_getCurrentCRR();
    static double virtualbike_getCurrentCW();
    static double virtualbike_getPowerRequested();
    static bool virtualbike_updateFTMS(unsigned short normalizeSpeed, unsigned char currentResistance,
                                unsigned short currentCadence, unsigned short currentWatt,
                                unsigned short CrankRevolutions, unsigned short LastCrankEventTime);
    static int virtualbike_getLastFTMSMessage(unsigned char *message);

    // virtualrower
    static void virtualrower_ios();
    static void virtualrower_setHeartRate(unsigned char heartRate);
    static bool virtualrower_updateFTMS(unsigned short normalizeSpeed, unsigned char currentResistance,
                                 unsigned short currentCadence, unsigned short currentWatt,
                                 unsigned short CrankRevolutions, unsigned short LastCrankEventTime,
                                 unsigned short StrokesCount, unsigned int Distance, unsigned short KCal,
                                 unsigned short Pace);
    static int virtualrower_getLastFTMSMessage(unsigned char *message);

    // virtualtreadmill
    static void virtualtreadmill_zwift_ios();
    static void virtualtreadmill_setHeartRate(unsigned char heartRate);
    static double virtualtreadmill_getCurrentSlope();
    static uint64_t virtualtreadmill_lastChangeCurrentSlope();
    static double virtualtreadmill_getPowerRequested();
    static bool virtualtreadmill_updateFTMS(unsigned short normalizeSpeed, unsigned char currentResistance,
                                     unsigned short currentCadence, unsigned short currentWatt,
                                     unsigned short currentInclination);

    // volume
    static double getVolume();
};

#endif // LOCKSCREEN_H
