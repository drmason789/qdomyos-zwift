#include <QtTest>

// add necessary includes here

class PafersBike : public QObject
{
    Q_OBJECT

public:
    PafersBike();
    ~PafersBike();

private slots:
    void test_case1();

};

PafersBike::PafersBike()
{

}

PafersBike::~PafersBike()
{

}

void PafersBike::test_case1()
{

}



#include "tst_pafersbike.moc"


