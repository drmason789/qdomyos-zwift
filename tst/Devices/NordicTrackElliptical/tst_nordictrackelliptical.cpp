#include <QtTest>

// add necessary includes here

class NordicTrackElliptical : public QObject
{
    Q_OBJECT

public:
    NordicTrackElliptical();
    ~NordicTrackElliptical();

private slots:
    void test_case1();

};

NordicTrackElliptical::NordicTrackElliptical()
{

}

NordicTrackElliptical::~NordicTrackElliptical()
{

}

void NordicTrackElliptical::test_case1()
{

}

QTEST_APPLESS_MAIN(NordicTrackElliptical)



#include "tst_nordictrackelliptical.moc"


