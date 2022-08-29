#include <QtTest>

// add necessary includes here

class PafersTreadmill : public QObject
{
    Q_OBJECT

public:
    PafersTreadmill();
    ~PafersTreadmill();

private slots:
    void test_case1();

};

PafersTreadmill::PafersTreadmill()
{

}

PafersTreadmill::~PafersTreadmill()
{

}

void PafersTreadmill::test_case1()
{

}

QTEST_APPLESS_MAIN(PafersTreadmill)



#include "tst_paferstreadmill.moc"


