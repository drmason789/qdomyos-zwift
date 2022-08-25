#include <QtTest>

// add necessary includes here

class NordicTrackIFitADBTreadmill : public QObject
{
    Q_OBJECT

public:
    NordicTrackIFitADBTreadmill();
    ~NordicTrackIFitADBTreadmill();

private slots:
    void test_case1();

};

NordicTrackIFitADBTreadmill::NordicTrackIFitADBTreadmill()
{

}

NordicTrackIFitADBTreadmill::~NordicTrackIFitADBTreadmill()
{

}

void NordicTrackIFitADBTreadmill::test_case1()
{

}



#include "tst_nordictrackifitadbtreadmill.moc"


