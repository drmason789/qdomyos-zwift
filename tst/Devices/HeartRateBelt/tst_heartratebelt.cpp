#include <QtTest>

// add necessary includes here

class HeartRateBelt : public QObject
{
    Q_OBJECT

public:
    HeartRateBelt();
    ~HeartRateBelt();

private slots:
    void test_case1();

};

HeartRateBelt::HeartRateBelt()
{

}

HeartRateBelt::~HeartRateBelt()
{

}

void HeartRateBelt::test_case1()
{

}



#include "tst_heartratebelt.moc"


