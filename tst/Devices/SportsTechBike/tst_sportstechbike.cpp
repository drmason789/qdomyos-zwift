#include <QtTest>

// add necessary includes here

class SportsTechBike : public QObject
{
    Q_OBJECT

public:
    SportsTechBike();
    ~SportsTechBike();

private slots:
    void test_case1();

};

SportsTechBike::SportsTechBike()
{

}

SportsTechBike::~SportsTechBike()
{

}

void SportsTechBike::test_case1()
{

}

QTEST_APPLESS_MAIN(SportsTechBike)



#include "tst_sportstechbike.moc"


