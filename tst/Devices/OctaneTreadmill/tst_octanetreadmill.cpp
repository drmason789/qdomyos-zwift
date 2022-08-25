#include <QtTest>

// add necessary includes here

class OctaneTreadmill : public QObject
{
    Q_OBJECT

public:
    OctaneTreadmill();
    ~OctaneTreadmill();

private slots:
    void test_case1();

};

OctaneTreadmill::OctaneTreadmill()
{

}

OctaneTreadmill::~OctaneTreadmill()
{

}

void OctaneTreadmill::test_case1()
{

}



#include "tst_octanetreadmill.moc"


