#include <QtTest>

// add necessary includes here

class FTMSBike : public QObject
{
    Q_OBJECT

public:
    FTMSBike();
    ~FTMSBike();

private slots:
    void test_case1();

};

FTMSBike::FTMSBike()
{

}

FTMSBike::~FTMSBike()
{

}

void FTMSBike::test_case1()
{

}



#include "tst_ftmsbike.moc"


