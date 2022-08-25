#include <QtTest>

// add necessary includes here

class SnodeBike : public QObject
{
    Q_OBJECT

public:
    SnodeBike();
    ~SnodeBike();

private slots:
    void test_case1();

};

SnodeBike::SnodeBike()
{

}

SnodeBike::~SnodeBike()
{

}

void SnodeBike::test_case1()
{

}



#include "tst_snodebike.moc"


