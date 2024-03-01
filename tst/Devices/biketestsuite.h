#pragma once

#include "gtest/gtest.h"
#include "devices.h"
#include "ErgInterface/erginterface.h"

#include "Tools/testsettings.h"

template <typename T>
class BikeTestSuite : public testing::Test {
private:
    bike * device = nullptr;

protected:
    T typeParam;

    uint32_t maxRPM, minRPM;
    resistance_t maxResistance, minResistance;

    erginterface * ergInterface = nullptr;

    /**
     * @brief Manages the QSettings used during the tests, separate from QSettings stored in the system generally.
     */
    TestSettings testSettings;
public:
    BikeTestSuite();

    // Sets up the test fixture.
    void SetUp() override;

    // Tears down the test fixture.
    virtual void TearDown() override;

    void test_powerFunctions_minCadence();
    void test_powerFunctions_minResistance();
    void test_powerFunctions_maxCadence();
    void test_powerFunctions_maxResistance();
    void test_powerFunctions_resistancePowerConversion();

};


TYPED_TEST_SUITE(BikeTestSuite, BikeTestDataTypes);

TYPED_TEST(BikeTestSuite, TestPowerFunctionsMinCadence) {
    this->test_powerFunctions_minCadence();
}

TYPED_TEST(BikeTestSuite, TestPowerFunctionsMaxCadence) {
    this->test_powerFunctions_maxCadence();
}

TYPED_TEST(BikeTestSuite, TestPowerFunctionsMinResistance) {
    this->test_powerFunctions_minResistance();
}

TYPED_TEST(BikeTestSuite, TestPowerFunctionsMaxResistance) {
    this->test_powerFunctions_maxResistance();
}

TYPED_TEST(BikeTestSuite, TestPowerFunctionsResistancePowerConversion) {
    this->test_powerFunctions_resistancePowerConversion();
}

