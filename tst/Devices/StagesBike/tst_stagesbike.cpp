#include <QtTest>

// add necessary includes here

class StagesBike : public QObject
{
    Q_OBJECT

public:
    StagesBike();
    ~StagesBike();

private slots:
    void test_case1();

};

StagesBike::StagesBike()
{

}

StagesBike::~StagesBike()
{

}

void StagesBike::test_case1()
{

}

QTEST_APPLESS_MAIN(StagesBike)



#include "tst_stagesbike.moc"


