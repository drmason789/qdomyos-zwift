#include <QtTest>

// add necessary includes here

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

}

#include "tst_activiotreadmill.moc"


