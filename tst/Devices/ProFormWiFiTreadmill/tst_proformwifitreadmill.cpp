#include <QtTest>

// add necessary includes here

class ProFormWiFiTreadmill : public QObject
{
    Q_OBJECT

public:
    ProFormWiFiTreadmill();
    ~ProFormWiFiTreadmill();

private slots:
    void test_case1();

};

ProFormWiFiTreadmill::ProFormWiFiTreadmill()
{

}

ProFormWiFiTreadmill::~ProFormWiFiTreadmill()
{

}

void ProFormWiFiTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormWiFiTreadmill)



#include "tst_proformwifitreadmill.moc"


