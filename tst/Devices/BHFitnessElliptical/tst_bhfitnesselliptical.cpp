#include <QtTest>

// add necessary includes here

class BHFitnessElliptical : public QObject
{
    Q_OBJECT

public:
    BHFitnessElliptical();
    ~BHFitnessElliptical();

private slots:
    void test_case1();

};

BHFitnessElliptical::BHFitnessElliptical()
{

}

BHFitnessElliptical::~BHFitnessElliptical()
{

}

void BHFitnessElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(BHFitnessElliptical)

#include "tst_bhfitnesselliptical.moc"


