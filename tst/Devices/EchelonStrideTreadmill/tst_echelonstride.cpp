#include <QtTest>

// add necessary includes here

class EchelonStrideTreadmill : public QObject
{
    Q_OBJECT

public:
    EchelonStrideTreadmill();
    ~EchelonStrideTreadmill();

private slots:
    void test_case1();

};

EchelonStrideTreadmill::EchelonStrideTreadmill()
{

}

EchelonStrideTreadmill::~EchelonStrideTreadmill()
{

}

void EchelonStrideTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(EchelonStrideTreadmill)



#include "tst_echelonstride.moc"


