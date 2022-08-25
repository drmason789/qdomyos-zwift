#include <QtTest>

// add necessary includes here

class Chronobike : public QObject
{
    Q_OBJECT

public:
    Chronobike();
    ~Chronobike();

private slots:
    void test_case1();

};

Chronobike::Chronobike()
{

}

Chronobike::~Chronobike()
{

}

void Chronobike::test_case1()
{

}



#include "tst_chronobike.moc"


