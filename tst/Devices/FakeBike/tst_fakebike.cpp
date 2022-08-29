#include <QtTest>

// add necessary includes here

class FakeBike : public QObject
{
    Q_OBJECT

public:
    FakeBike();
    ~FakeBike();

private slots:
    void test_case1();

};

FakeBike::FakeBike()
{

}

FakeBike::~FakeBike()
{

}

void FakeBike::test_case1()
{

}

QTEST_APPLESS_MAIN(FakeBike)



#include "tst_fakebike.moc"


