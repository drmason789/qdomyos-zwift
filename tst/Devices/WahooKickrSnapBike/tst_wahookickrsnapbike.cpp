#include <QtTest>

// add necessary includes here

class WahooKickrSnapBike : public QObject
{
    Q_OBJECT

public:
    WahooKickrSnapBike();
    ~WahooKickrSnapBike();

private slots:
    void test_case1();

};

WahooKickrSnapBike::WahooKickrSnapBike()
{

}

WahooKickrSnapBike::~WahooKickrSnapBike()
{

}

void WahooKickrSnapBike::test_case1()
{

}

QTEST_APPLESS_MAIN(WahooKickrSnapBike)



#include "tst_wahookickrsnapbike.moc"


