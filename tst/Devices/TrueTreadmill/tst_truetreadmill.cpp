#include <QtTest>

// add necessary includes here

class TrueTreadmill : public QObject
{
    Q_OBJECT

public:
    TrueTreadmill();
    ~TrueTreadmill();

private slots:
    void test_case1();

};

TrueTreadmill::TrueTreadmill()
{

}

TrueTreadmill::~TrueTreadmill()
{

}

void TrueTreadmill::test_case1()
{

}



#include "tst_truetreadmill.moc"


