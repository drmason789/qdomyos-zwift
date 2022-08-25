#include <QtTest>

// add necessary includes here

class SpiritTreadmill : public QObject
{
    Q_OBJECT

public:
    SpiritTreadmill();
    ~SpiritTreadmill();

private slots:
    void test_case1();

};

SpiritTreadmill::SpiritTreadmill()
{

}

SpiritTreadmill::~SpiritTreadmill()
{

}

void SpiritTreadmill::test_case1()
{

}



#include "tst_spirittreadmill.moc"


