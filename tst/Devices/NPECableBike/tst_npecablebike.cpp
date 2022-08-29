#include <QtTest>

// add necessary includes here

class NPECableBike : public QObject
{
    Q_OBJECT

public:
    NPECableBike();
    ~NPECableBike();

private slots:
    void test_case1();

};

NPECableBike::NPECableBike()
{

}

NPECableBike::~NPECableBike()
{

}

void NPECableBike::test_case1()
{

}

QTEST_APPLESS_MAIN(NPECableBike)



#include "tst_npecablebike.moc"


