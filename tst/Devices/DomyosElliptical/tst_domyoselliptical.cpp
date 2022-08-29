#include <QtTest>

// add necessary includes here

class DomyosElliptical : public QObject
{
    Q_OBJECT

public:
    DomyosElliptical();
    ~DomyosElliptical();

private slots:
    void test_case1();

};

DomyosElliptical::DomyosElliptical()
{

}

DomyosElliptical::~DomyosElliptical()
{

}

void DomyosElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(DomyosElliptical)



#include "tst_domyoselliptical.moc"


