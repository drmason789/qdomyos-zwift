#include <QtTest>

// add necessary includes here

class YesoulBike : public QObject
{
    Q_OBJECT

public:
    YesoulBike();
    ~YesoulBike();

private slots:
    void test_case1();

};

YesoulBike::YesoulBike()
{

}

YesoulBike::~YesoulBike()
{

}

void YesoulBike::test_case1()
{

}

QTEST_APPLESS_MAIN(YesoulBike)



#include "tst_yesoulbike.moc"


