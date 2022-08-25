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



#include "tst_bike.moc"


