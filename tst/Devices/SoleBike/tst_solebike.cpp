#include <QtTest>

// add necessary includes here

class SoleBike : public QObject
{
    Q_OBJECT

public:
    SoleBike();
    ~SoleBike();

private slots:
    void test_case1();

};

SoleBike::SoleBike()
{

}

SoleBike::~SoleBike()
{

}

void SoleBike::test_case1()
{

}



#include "tst_solebike.moc"


