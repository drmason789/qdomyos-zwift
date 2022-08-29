#include <QtTest>

// add necessary includes here

class ProFormEllipticalTrainer : public QObject
{
    Q_OBJECT

public:
    ProFormEllipticalTrainer();
    ~ProFormEllipticalTrainer();

private slots:
    void test_case1();

};

ProFormEllipticalTrainer::ProFormEllipticalTrainer()
{

}

ProFormEllipticalTrainer::~ProFormEllipticalTrainer()
{

}

void ProFormEllipticalTrainer::test_case1()
{

}

QTEST_APPLESS_MAIN(ProFormEllipticalTrainer)



#include "tst_proformellipticaltrainer.moc"


