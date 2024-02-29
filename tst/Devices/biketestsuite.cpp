#include "biketestsuite.h"
#include "ErgInterface/bikeergfunctions.h"

template<typename T>
void BikeTestSuite<T>::SetUp() {}

template<typename T>
void BikeTestSuite<T>::test_powerFunctions() {
    BikeOptions options;
    auto device = std::unique_ptr<bike>(this->typeParam.createInstance(options));
    auto erg = std::unique_ptr<erginterface>(new bikeergfunctions(device.get()));

    const uint32_t maxRPM = erg->getMaxCadence().value_or(255);
    const uint32_t minRPM = erg->getMinCadence().value_or(1);
    const resistance_t maxResistance = erg->getMaxResistance().value_or(255);
    const resistance_t minResistance = erg->getMinResistance().value_or(0);

    uint16_t p0, p1;

    // traverse the cadence edges checking the power is clipped to the values for the max and min resistance
    for(uint32_t cadenceRPM=minRPM; cadenceRPM<=maxRPM; cadenceRPM++)
    {
        if(erg->getMaxResistance().has_value()) {
            p0 = erg->getPower(cadenceRPM, maxResistance);
            p1 = erg->getPower(cadenceRPM, maxResistance+1);

            EXPECT_EQ(p0, p1) << "expected power to stop increasing at max resistance, at cadence " << cadenceRPM << " RPM";
        }

        if(erg->getMinResistance().has_value()) {
            p0 = erg->getPower(cadenceRPM, minResistance);
            p1 = erg->getPower(cadenceRPM, minResistance-1);

            EXPECT_EQ(p0, p1) << "expected power to stop decreasing at min resistance, at cadence " << cadenceRPM << " RPM";
        }
    }

    // traverse the resistance edge checking the power is clipped to the values for the max and min cadence
    for(resistance_t r=minResistance; r<=maxResistance; r++)
    {
        if(erg->getMinCadence().has_value()) {
            p0 = erg->getPower(minRPM, r);
            p1 = erg->getPower(minRPM-1, r);

            ASSERT_EQ(p0, p1) << "expected power to stop decreasing at min cadence, for resistance " << r ;
        }

        if(erg->getMaxCadence().has_value()) {
            p0 = erg->getPower(maxRPM, r);
            p1 = erg->getPower(maxRPM+1, r);

            ASSERT_EQ(p0, p1) << "expected power to stop increasing at max cadence, for resistance " << r ;
        }
    }

    // test inverses
    for(uint32_t cadenceRPM=minRPM; cadenceRPM<=maxRPM; cadenceRPM++)
    {
        uint16_t lastPower=0xFFFF;
        for(resistance_t r=minResistance; r<=maxResistance; r++)
        {
            uint16_t power = erg->getPower(cadenceRPM, r);

            if(power!=lastPower)
            {
                lastPower = power;
                resistance_t resistance = erg->getResistance(cadenceRPM, power);

                ASSERT_EQ(r, resistance) << "unexpected resistance to achieve " << power << "W at " <<cadenceRPM << "RPM";
            }

        }
    }

}
