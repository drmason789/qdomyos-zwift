#include <QtTest>

// add necessary includes here

class SportsPlusBike : public QObject
{
    Q_OBJECT

public:
    SportsPlusBike();
    ~SportsPlusBike();

private slots:
    void test_case1();

};

SportsPlusBike::SportsPlusBike()
{

}

SportsPlusBike::~SportsPlusBike()
{

}

void SportsPlusBike::test_case1()
{

}



#include "tst_sportsplusbike.moc"


