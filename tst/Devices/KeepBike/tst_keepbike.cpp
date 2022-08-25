#include <QtTest>

// add necessary includes here

class KeepBike : public QObject
{
    Q_OBJECT

public:
    KeepBike();
    ~KeepBike();

private slots:
    void test_case1();

};

KeepBike::KeepBike()
{

}

KeepBike::~KeepBike()
{

}

void KeepBike::test_case1()
{

}



#include "tst_keepbike.moc"


