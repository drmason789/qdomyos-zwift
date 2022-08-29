#include <QtTest>

// add necessary includes here

class Rower : public QObject
{
    Q_OBJECT

public:
    Rower();
    ~Rower();

private slots:
    void test_case1();

};

Rower::Rower()
{

}

Rower::~Rower()
{

}

void Rower::test_case1()
{

}

QTEST_APPLESS_MAIN(Rower)



#include "tst_rower.moc"


