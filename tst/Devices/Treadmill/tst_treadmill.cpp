#include <QtTest>

// add necessary includes here

class Treadmill : public QObject
{
    Q_OBJECT

public:
    Treadmill();
    ~Treadmill();

private slots:
    void test_case1();

};

Treadmill::Treadmill()
{

}

Treadmill::~Treadmill()
{

}

void Treadmill::test_case1()
{

}



#include "tst_treadmill.moc"


