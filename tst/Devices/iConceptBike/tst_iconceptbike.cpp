#include <QtTest>

// add necessary includes here

class iConceptBike : public QObject
{
    Q_OBJECT

public:
    iConceptBike();
    ~iConceptBike();

private slots:
    void test_case1();

};

iConceptBike::iConceptBike()
{

}

iConceptBike::~iConceptBike()
{

}

void iConceptBike::test_case1()
{

}

QTEST_APPLESS_MAIN(iConceptBike)



#include "tst_iconceptbike.moc"


