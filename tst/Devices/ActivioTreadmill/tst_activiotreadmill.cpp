#include <QtTest>

// add necessary includes here
#include "activiotreadmill.h"

class ActivioTreadmill : public QObject
{
    Q_OBJECT

public:
    ActivioTreadmill();
    ~ActivioTreadmill();

private slots:
    void test_case1();

};

ActivioTreadmill::ActivioTreadmill()
{

}

ActivioTreadmill::~ActivioTreadmill()
{

}

void ActivioTreadmill::test_case1()
{
    activiotreadmill * treadmill = new activiotreadmill();

    delete treadmill;
}

QTEST_APPLESS_MAIN(ActivioTreadmill)

#include "tst_activiotreadmill.moc"


