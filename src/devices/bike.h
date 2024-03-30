#ifndef BIKE_H
#define BIKE_H

#include "devices/bluetoothdevice.h"
#include "virtualdevices/virtualbike.h"
#include <QObject>

class bike : public bluetoothdevice {

    Q_OBJECT

  public:
    bike();

    virtualbike *VirtualBike();

    metric lastRequestedResistance();
    metric lastRequestedPelotonResistance();
    metric lastRequestedCadence();
    metric lastRequestedPower();
    metric currentResistance() override;
    uint8_t fanSpeed() override;
    double currentCrankRevolutions() override;
    uint16_t lastCrankEventTime() override;
    bool connected() override;
    virtual power_t watts();
    virtual resistance_t pelotonToBikeResistance(peloton_t pelotonResistance);
    virtual resistance_t resistanceFromPowerRequest(power_t power);
    virtual power_t powerFromResistanceRequest(resistance_t requestResistance);
    virtual bool ergManagedBySS2K() { return false; }
    bluetoothdevice::BLUETOOTH_TYPE deviceType() override;
    metric pelotonResistance();
    void clearStats() override;
    void setLap() override;
    void setPaused(bool p) override;
    uint8_t metrics_override_heartrate() override;
    void setGears(double d);
    double gears();
    void setSpeedLimit(double speed) { m_speedLimit = speed; }
    double speedLimit() { return m_speedLimit; }

    /**
     * @brief currentSteeringAngle Gets a metric object to get or set the current steering angle
     * for the Elite Sterzo or emulating device. Expected range -45 to +45 degrees.
     * @return A metric object.
     */
    metric currentSteeringAngle() { return m_steeringAngle; }
    virtual bool inclinationAvailableByHardware();
    bool ergModeSupportedAvailableByHardware() { return ergModeSupported; }

  public Q_SLOTS:
    void changeResistance(resistance_t res) override;
    virtual void changeCadence(cadence_t cad);
    void changePower(power_t power) override;
    virtual void changeRequestedPelotonResistance(peloton_t resistance);
    void cadenceSensor(cadence_t cadence) override;
    void powerSensor(power_t power) override;
    void changeInclination(double grade, double percentage) override;
    virtual void changeSteeringAngle(double angle) { m_steeringAngle = angle; }
    virtual void resistanceFromFTMSAccessory(resistance_t res) { Q_UNUSED(res); }
    void gearUp() {QSettings settings; setGears(gears() +
                               settings.value(QZSettings::gears_gain, QZSettings::default_gears_gain).toDouble());}
    void gearDown() {QSettings settings; setGears(gears() -
                               settings.value(QZSettings::gears_gain, QZSettings::default_gears_gain).toDouble());}

  Q_SIGNALS:
    void bikeStarted();
    void resistanceChanged(resistance_t resistance);
    void resistanceRead(resistance_t resistance);
    void steeringAngleChanged(double angle);

  protected:
    metric RequestedResistance;
    metric RequestedPelotonResistance;
    metric RequestedCadence;
    metric RequestedPower;

    resistance_t requestResistance = -1;
    inclination_t requestInclination = -100;
    power_t requestPower = -1;

    bool ergModeSupported = false; // if a bike has this mode supported, when from the virtual bike there is a power
                                   // request there is no need to translate in resistance levels

    double m_gears = 0;
    resistance_t lastRawRequestedResistanceValue = -1;
    double lastRawRequestedInclinationValue = -100;
    uint16_t LastCrankEventTime = 0;
    double CrankRevs = 0;

    metric m_pelotonResistance;

    metric m_steeringAngle;

    double m_speedLimit = 0;

    power_t wattFromHR(bool useSpeedAndCadence);
};

#endif // BIKE_H
