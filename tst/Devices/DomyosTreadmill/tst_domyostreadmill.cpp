#include <QtTest>

// add necessary includes here

class DomyosTreadmill : public QObject
{
    Q_OBJECT

public:
    DomyosTreadmill();
    ~DomyosTreadmill();

private slots:
    void test_case1();

};

DomyosTreadmill::DomyosTreadmill()
{

}

DomyosTreadmill::~DomyosTreadmill()
{

}

void DomyosTreadmill::test_case1()
{

}



#include "tst_domyostreadmill.moc"


