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
    resistance_t r0, r1;
    QStringList errors;
    QString  powerBeyondResistanceLimit = QStringLiteral("Power at C:%1 RPM not confined at %6 resistance (R:%2, P:%3W), (R:%4, P:%5W)");

    // traverse the cadence edges checking the power is clipped to the values for the max and min resistance
    for(uint32_t cadenceRPM=minRPM; cadenceRPM<=maxRPM; cadenceRPM++)
    {
        if(erg->getMaxResistance().has_value()) {

            r0 = maxResistance;
            r1 = maxResistance+1;
            p0 = erg->getPower(cadenceRPM, r0);
            p1 = erg->getPower(cadenceRPM, r1);

            if(p0 != p1)
                errors.append(powerBeyondResistanceLimit.arg(cadenceRPM).arg(r0).arg(p0).arg(r1).arg(p1).arg("maximum"));
        }

        if(erg->getMinResistance().has_value()) {
            r0 = minResistance;
            r1 = minResistance-1;
            p0 = erg->getPower(cadenceRPM, r0);
            p1 = erg->getPower(cadenceRPM, r1);

            if(p0 != p1)
                errors.append(powerBeyondResistanceLimit.arg(cadenceRPM).arg(r0).arg(p0).arg(r1).arg(p1).arg("minimum"));
        }
    }

    // traverse the resistance edge checking the power is clipped to the values for the max and min cadence

    QString  powerBeyondCadenceLimit = QStringLiteral("Power at R:%1 not confined at %6 cadence (C:%2 RPM, P:%3W), (C:%4 RPM, P:%5W)");


    for(resistance_t r=minResistance; r<=maxResistance; r++)
    {
        if(erg->getMinCadence().has_value()) {
            const int32_t c0 = minRPM, c1=minRPM-1;
            p0 = erg->getPower(c0, r);
            p1 = erg->getPower(c1, r);

            if(p0!=p1)
                errors.append(powerBeyondCadenceLimit.arg(r).arg(c0).arg(p0).arg(c1).arg(p1).arg("minimum"));
        }

        if(erg->getMaxCadence().has_value()) {
            const int32_t c0 = maxRPM, c1=maxRPM+1;
            p0 = erg->getPower(c0, r);
            p1 = erg->getPower(c1, r);

            if(p0!=p1)
                errors.append(powerBeyondCadenceLimit.arg(r).arg(c0).arg(p0).arg(c1).arg(p1).arg("maximum"));
        }
    }

    // test inverses
    QString unexpectedResistance=QStringLiteral("Expected resistance R:%1 to achieve P:%2 W at C:%3 RPM, but got R:%4");
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

                if(r!=resistance)
                    errors.append(unexpectedResistance.arg(resistance).arg(power).arg(cadenceRPM).arg(r));

            }

        }
    }

    if(!errors.empty()){
        auto errorMessage = errors.join('\n').toStdString();

        FAIL() << errorMessage;
    }

}
