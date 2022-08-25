#include <QtTest>

// add necessary includes here

class FlywheelBike : public QObject
{
    Q_OBJECT

public:
    FlywheelBike();
    ~FlywheelBike();

private slots:
    void test_case1();

};

FlywheelBike::FlywheelBike()
{

}

FlywheelBike::~FlywheelBike()
{

}

void FlywheelBike::test_case1()
{

}



#include "tst_flywheelbike.moc"


