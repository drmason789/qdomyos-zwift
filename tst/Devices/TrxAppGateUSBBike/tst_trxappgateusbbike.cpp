#include <QtTest>

// add necessary includes here

class TrxAppGateUSBBike : public QObject
{
    Q_OBJECT

public:
    TrxAppGateUSBBike();
    ~TrxAppGateUSBBike();

private slots:
    void test_case1();

};

TrxAppGateUSBBike::TrxAppGateUSBBike()
{

}

TrxAppGateUSBBike::~TrxAppGateUSBBike()
{

}

void TrxAppGateUSBBike::test_case1()
{

}

QTEST_APPLESS_MAIN(TrxAppGateUSBBike)



#include "tst_trxappgateusbbike.moc"


