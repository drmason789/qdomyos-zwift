#include <QtTest>

// add necessary includes here

//#include "tst_bluetoothdevice.h"
#include "autotest.h"

class NordicTrackIFitADBTreadmill : public QObject
{
	Q_OBJECT

public:
	// QTEST macro so that QtCreator recognises the test
	// This is inside the class definition to avoid repeated definitions.
	QTEST_APPLESS_MAIN(NordicTrackIFitADBTreadmill)

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

DECLARE_TEST(NordicTrackIFitADBTreadmill)



#include "tst_nordictrackifitadbtreadmill.moc"


