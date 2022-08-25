#include <QtTest>

// add necessary includes here

class Elliptical : public QObject
{
    Q_OBJECT

public:
    Elliptical();
    ~Elliptical();

private slots:
    void test_case1();

};

Elliptical::Elliptical()
{

}

Elliptical::~Elliptical()
{

}

void Elliptical::test_case1()
{

}



#include "tst_elliptical.moc"


