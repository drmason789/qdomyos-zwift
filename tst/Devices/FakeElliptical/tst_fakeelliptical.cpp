#include <QtTest>

// add necessary includes here

class FakeElliptical : public QObject
{
    Q_OBJECT

public:
    FakeElliptical();
    ~FakeElliptical();

private slots:
    void test_case1();

};

FakeElliptical::FakeElliptical()
{

}

FakeElliptical::~FakeElliptical()
{

}

void FakeElliptical::test_case1()
{

}



#include "tst_fakeelliptical.moc"


