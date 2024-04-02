#ifndef ELLIPTICAL_H
#define ELLIPTICAL_H
#include "devices/bluetoothdevice.h"
#include <QObject>

class elliptical : public bluetoothdevice {
    Q_OBJECT

  public:
    elliptical();
    metric lastRequestedPelotonResistance();
    void update_metrics(bool watt_calc, const double watts);
    metric lastRequestedCadence();
    metric lastRequestedResistance();
    metric lastRequestedSpeed() { return RequestedSpeed; }
    metric currentInclination() override;
    metric currentResistance() override;
    virtual double requestedSpeed();
    uint8_t fanSpeed() override;
    double currentCrankRevolutions() override;
    uint16_t lastCrankEventTime() override;
    bool connected() override;
    metric pelotonResistance();
    virtual resistance_t pelotonToEllipticalResistance(peloton_t pelotonResistance);
    virtual bool inclinationAvailableByHardware();
    bluetoothdevice::BLUETOOTH_TYPE deviceType() override;
    void clearStats() override;
    void setPaused(bool p) override;
    void setLap() override;
    virtual power_t watts();
    double speedFromWatts();
    void setGears(double d);
    double gears();
    virtual double minStepInclination() { return 0.5; }

  public Q_SLOTS:
    virtual void changeSpeed(double speed);
    void changeResistance(resistance_t res) override;
    void changeInclination(double grade, double inclination) override;
    virtual void changeCadence(cadence_t cad);
    virtual void changeRequestedPelotonResistance(peloton_t resistance);

  signals:
    void bikeStarted();

  protected:
    metric RequestedResistance;
    metric RequestedCadence;
    metric RequestedSpeed;
    metric RequestedPelotonResistance;
    metric Resistance;
    metric m_pelotonResistance;
    uint16_t LastCrankEventTime = 0;
    resistance_t requestResistance = -1;
    volatile double requestSpeed = -1;
    double requestInclination = -100;
    double CrankRevs = 0;
    double m_gears = 0;
    resistance_t lastRawRequestedResistanceValue = -1;
};

#endif // ELLIPTICAL_H
