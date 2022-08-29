#include <QtTest>

// add necessary includes here

class BowflexTreadmill : public QObject
{
    Q_OBJECT

public:
    BowflexTreadmill();
    ~BowflexTreadmill();

private slots:
    void test_case1();

};

BowflexTreadmill::BowflexTreadmill()
{

}

BowflexTreadmill::~BowflexTreadmill()
{

}

void BowflexTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(BowflexTreadmill)


#include "tst_bowflextreadmill.moc"



