#include <QtTest>

// add necessary includes here

class RenphoBike : public QObject
{
    Q_OBJECT

public:
    RenphoBike();
    ~RenphoBike();

private slots:
    void test_case1();

};

RenphoBike::RenphoBike()
{

}

RenphoBike::~RenphoBike()
{

}

void RenphoBike::test_case1()
{

}



#include "tst_renphobike.moc"


