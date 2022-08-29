#include <QtTest>

// add necessary includes here

class EchelonRower : public QObject
{
    Q_OBJECT

public:
    EchelonRower();
    ~EchelonRower();

private slots:
    void test_case1();

};

EchelonRower::EchelonRower()
{

}

EchelonRower::~EchelonRower()
{

}

void EchelonRower::test_case1()
{

}

QTEST_APPLESS_MAIN(EchelonRower)



#include "tst_echelonrower.moc"


