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

QTEST_APPLESS_MAIN(OctaneTreadmill)



#include "tst_octanetreadmill.moc"


