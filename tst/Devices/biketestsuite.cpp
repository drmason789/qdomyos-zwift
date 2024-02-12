#include "biketestsuite.h"

template<typename T>
void BikeTestSuite<T>::SetUp() {}

template<typename T>
void BikeTestSuite<T>::test_powerFunctions() {
    BikeOptions options;
    auto device = std::unique_ptr<bike>(this->typeParam.createInstance(options));


    const uint32_t maxRPM = 120;
    const uint32_t minRPM = 30;
    const resistance_t maxResistance = device->maxResistance();
    const resistance_t minResistance = 0;

    uint16_t p0, p1;

    // traverse the cadence edges checking the power is clipped to the values for the max and min resistance
    for(uint32_t cadenceRPM=minRPM; cadenceRPM<=maxRPM; cadenceRPM++)
    {
        device->cadenceSensor(cadenceRPM);
        p0 = device->powerFromResistanceRequest(maxResistance);
        p1 = device->powerFromResistanceRequest(maxResistance+1);

        ASSERT_EQ(p0, p1) << "expected power to stop increasing at max resistance, at cadence " << cadenceRPM << " RPM";

        p0 = device->powerFromResistanceRequest(minResistance);
        p1 = device->powerFromResistanceRequest(minResistance-1);

        ASSERT_EQ(p0, p1) << "expected power to stop decreasing at min resistance, at cadence " << cadenceRPM << " RPM";
    }

    // traverse the resistance edge checking the power is clipped to the values for the max and min cadence
    for(resistance_t r=minResistance; r<=maxResistance; r++)
    {
        device->cadenceSensor(minRPM);
        p0 = device->powerFromResistanceRequest(r);
        device->cadenceSensor(minRPM-1);
        p1 = device->powerFromResistanceRequest(r);

        ASSERT_EQ(p0, p1) << "expected power to stop decreasing at min cadence, for resistance " << r ;

        device->cadenceSensor(maxRPM);
        p0 = device->powerFromResistanceRequest(r);
        device->cadenceSensor(maxRPM+1);
        p1 = device->powerFromResistanceRequest(r);

        ASSERT_EQ(p0, p1) << "expected power to stop increasing at max cadence, for resistance " << r ;
    }

    // test inverses
    for(uint32_t cadenceRPM=minRPM; cadenceRPM<=maxRPM; cadenceRPM++)
    {
        uint16_t lastPower=0xFFFF;
        for(resistance_t r=minResistance; r<=maxResistance; r++)
        {
            device->cadenceSensor(cadenceRPM);
            uint16_t power = device->powerFromResistanceRequest(r);

            if(power!=lastPower)
            {
                lastPower = power;
                resistance_t resistance = device->resistanceFromPowerRequest(power);

                ASSERT_EQ(r, resistance) << "unexpected resistance to achieve " << power << "W at "<<cadenceRPM << "RPM";
            }

        }
    }

}
