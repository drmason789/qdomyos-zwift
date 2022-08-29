#include <QtTest>

// add necessary includes here

class ProFormElliptical : public QObject
{
    Q_OBJECT

public:
    ProFormElliptical();
    ~ProFormElliptical();

private slots:
    void test_case1();

};

ProFormElliptical::ProFormElliptical()
{

}

ProFormElliptical::~ProFormElliptical()
{

}

void ProFormElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormElliptical)



#include "tst_proformelliptical.moc"


