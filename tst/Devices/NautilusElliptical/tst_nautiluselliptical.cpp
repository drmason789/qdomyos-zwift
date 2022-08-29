#include <QtTest>

// add necessary includes here

class NautilusElliptical : public QObject
{
    Q_OBJECT

public:
    NautilusElliptical();
    ~NautilusElliptical();

private slots:
    void test_case1();

};

NautilusElliptical::NautilusElliptical()
{

}

NautilusElliptical::~NautilusElliptical()
{

}

void NautilusElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(NautilusElliptical)



#include "tst_nautiluselliptical.moc"


