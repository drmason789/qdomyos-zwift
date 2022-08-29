#include <QtTest>

// add necessary includes here

class MCFBike : public QObject
{
    Q_OBJECT

public:
    MCFBike();
    ~MCFBike();

private slots:
    void test_case1();

};

MCFBike::MCFBike()
{

}

MCFBike::~MCFBike()
{

}

void MCFBike::test_case1()
{

}

QTEST_APPLESS_MAIN(MCFBike)



#include "tst_mcfbike.moc"


