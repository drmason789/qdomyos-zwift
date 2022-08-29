#include <QtTest>

// add necessary includes here

class NautilusBike : public QObject
{
    Q_OBJECT

public:
    NautilusBike();
    ~NautilusBike();

private slots:
    void test_case1();

};

NautilusBike::NautilusBike()
{

}

NautilusBike::~NautilusBike()
{

}

void NautilusBike::test_case1()
{

}

QTEST_APPLESS_MAIN(NautilusBike)



#include "tst_nautilusbike.moc"


