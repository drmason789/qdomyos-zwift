#include <QtTest>

// add necessary includes here

class SoleElliptical : public QObject
{
    Q_OBJECT

public:
    SoleElliptical();
    ~SoleElliptical();

private slots:
    void test_case1();

};

SoleElliptical::SoleElliptical()
{

}

SoleElliptical::~SoleElliptical()
{

}

void SoleElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(SoleElliptical)



#include "tst_soleelliptical.moc"


