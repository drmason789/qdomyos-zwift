#include <QtTest>

// add necessary includes here

class ToorxTreadmill : public QObject
{
    Q_OBJECT

public:
    ToorxTreadmill();
    ~ToorxTreadmill();

private slots:
    void test_case1();

};

ToorxTreadmill::ToorxTreadmill()
{

}

ToorxTreadmill::~ToorxTreadmill()
{

}

void ToorxTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(ToorxTreadmill)



#include "tst_toorxtreadmill.moc"


