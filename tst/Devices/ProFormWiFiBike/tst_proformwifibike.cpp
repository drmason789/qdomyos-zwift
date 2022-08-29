#include <QtTest>

// add necessary includes here

class ProFormWiFiBike : public QObject
{
    Q_OBJECT

public:
    ProFormWiFiBike();
    ~ProFormWiFiBike();

private slots:
    void test_case1();

};

ProFormWiFiBike::ProFormWiFiBike()
{

}

ProFormWiFiBike::~ProFormWiFiBike()
{

}

void ProFormWiFiBike::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormWiFiBike)



#include "tst_proformwifibike.moc"


