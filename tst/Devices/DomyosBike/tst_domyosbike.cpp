#include <QtTest>

// add necessary includes here

class DomyosBike : public QObject
{
    Q_OBJECT

public:
    DomyosBike();
    ~DomyosBike();

private slots:
    void test_case1();

};

DomyosBike::DomyosBike()
{

}

DomyosBike::~DomyosBike()
{

}

void DomyosBike::test_case1()
{

}

QTEST_APPLESS_MAIN(DomyosBike)



#include "tst_domyosbike.moc"


