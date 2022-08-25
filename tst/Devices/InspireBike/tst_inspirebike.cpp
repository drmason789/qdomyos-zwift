#include <QtTest>

// add necessary includes here

class InspireBike : public QObject
{
    Q_OBJECT

public:
    InspireBike();
    ~InspireBike();

private slots:
    void test_case1();

};

InspireBike::InspireBike()
{

}

InspireBike::~InspireBike()
{

}

void InspireBike::test_case1()
{

}



#include "tst_inspirebike.moc"


