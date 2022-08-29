#include <QtTest>

// add necessary includes here

class StrydeRunPowerSensor : public QObject
{
    Q_OBJECT

public:
    StrydeRunPowerSensor();
    ~StrydeRunPowerSensor();

private slots:
    void test_case1();

};

StrydeRunPowerSensor::StrydeRunPowerSensor()
{

}

StrydeRunPowerSensor::~StrydeRunPowerSensor()
{

}

void StrydeRunPowerSensor::test_case1()
{

}

QTEST_APPLESS_MAIN(StrydeRunPowerSensor)



#include "tst_strydrunpowersensor.moc"


