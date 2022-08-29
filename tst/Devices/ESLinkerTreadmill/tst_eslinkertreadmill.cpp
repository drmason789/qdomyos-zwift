#include <QtTest>

// add necessary includes here

class ESLinkerTreadmill : public QObject
{
    Q_OBJECT

public:
    ESLinkerTreadmill();
    ~ESLinkerTreadmill();

private slots:
    void test_case1();

};

ESLinkerTreadmill::ESLinkerTreadmill()
{

}

ESLinkerTreadmill::~ESLinkerTreadmill()
{

}

void ESLinkerTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(ESLinkerTreadmill)



#include "tst_eslinkertreadmill.moc"


