#include <QtTest>

// add necessary includes here

class EliteSterzoSmart : public QObject
{
    Q_OBJECT

public:
    EliteSterzoSmart();
    ~EliteSterzoSmart();

private slots:
    void test_case1();

};

EliteSterzoSmart::EliteSterzoSmart()
{

}

EliteSterzoSmart::~EliteSterzoSmart()
{

}

void EliteSterzoSmart::test_case1()
{

}

QTEST_APPLESS_MAIN(EliteSterzoSmart)



#include "tst_elitesterzosmart.moc"


