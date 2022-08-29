#include <QtTest>

// add necessary includes here

class HeartRateBelt : public QObject
{
    Q_OBJECT

public:
    HeartRateBelt();
    ~HeartRateBelt();

private slots:
    void test_case1();

};

HeartRateBelt::HeartRateBelt()
{

}

HeartRateBelt::~HeartRateBelt()
{

}

void HeartRateBelt::test_case1()
{

}

QTEST_APPLESS_MAIN(HeartRateBelt)



#include "tst_heartratebelt.moc"


