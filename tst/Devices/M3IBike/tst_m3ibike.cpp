#include <QtTest>

// add necessary includes here

class M3IBike : public QObject
{
    Q_OBJECT

public:
    M3IBike();
    ~M3IBike();

private slots:
    void test_case1();

};

M3IBike::M3IBike()
{

}

M3IBike::~M3IBike()
{

}

void M3IBike::test_case1()
{

}

QTEST_APPLESS_MAIN(M3IBike)



#include "tst_m3ibike.moc"


