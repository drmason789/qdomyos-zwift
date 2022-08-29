#include <QtTest>

// add necessary includes here

class UltrasportBike : public QObject
{
    Q_OBJECT

public:
    UltrasportBike();
    ~UltrasportBike();

private slots:
    void test_case1();

};

UltrasportBike::UltrasportBike()
{

}

UltrasportBike::~UltrasportBike()
{

}

void UltrasportBike::test_case1()
{

}

QTEST_APPLESS_MAIN(UltrasportBike)



#include "tst_ultrasportbike.moc"


