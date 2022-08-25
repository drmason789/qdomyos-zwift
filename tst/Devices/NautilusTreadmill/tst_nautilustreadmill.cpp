#include <QtTest>

// add necessary includes here

class NautilusTreadmill : public QObject
{
    Q_OBJECT

public:
    NautilusTreadmill();
    ~NautilusTreadmill();

private slots:
    void test_case1();

};

NautilusTreadmill::NautilusTreadmill()
{

}

NautilusTreadmill::~NautilusTreadmill()
{

}

void NautilusTreadmill::test_case1()
{

}



#include "tst_nautilustreadmill.moc"


