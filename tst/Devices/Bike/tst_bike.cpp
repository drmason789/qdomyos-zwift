#include <QtTest>

// add necessary includes here

class Bike : public QObject
{
    Q_OBJECT

public:
    Bike();
    ~Bike();

private slots:
    void test_case1();

};

Bike::Bike()
{

}

Bike::~Bike()
{

}

void Bike::test_case1()
{

}

QTEST_APPLESS_MAIN(Bike)



#include "tst_bike.moc"


