#include <QtTest>

// add necessary includes here

class CSCBike : public QObject
{
    Q_OBJECT

public:
    CSCBike();
    ~CSCBike();

private slots:
    void test_case1();

};

CSCBike::CSCBike()
{

}

CSCBike::~CSCBike()
{

}

void CSCBike::test_case1()
{

}



#include "tst_cscbike.moc"


