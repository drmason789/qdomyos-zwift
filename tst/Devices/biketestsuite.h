#pragma once

#include "gtest/gtest.h"
#include "devices.h"

#include "Tools/testsettings.h"

template <typename T>
class BikeTestSuite : public testing::Test {

protected:
    T typeParam;

    /**
     * @brief Manages the QSettings used during the tests, separate from QSettings stored in the system generally.
     */
    TestSettings testSettings;
public:
    BikeTestSuite() : testSettings("Roberto Viola", "QDomyos-Zwift Testing") {}

    // Sets up the test fixture.
    void SetUp() override;

    // Tears down the test fixture.
    // virtual void TearDown();


    void test_powerFunctions();
};


TYPED_TEST_SUITE(BikeTestSuite, BikeTestDataTypes);

TYPED_TEST(BikeTestSuite, TestPowerFunctions) {
    this->test_powerFunctions();
}


