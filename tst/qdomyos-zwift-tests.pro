include(qdomyos-zwift-tests.pri)

TEMPLATE = lib

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

INCLUDEPATH += src/qmdnsengine/src/include Common

HEADERS += \
    Common/autotest.h \
    Common/tst_bluetoothdevice.h

SOURCES += \
    Common/tst_bluetoothdevice.cpp \
    Devices/ActivioTreadmill/tst_activiotreadmill.cpp \
    Devices/BHFitnessElliptical/tst_bhfitnesselliptical.cpp \
    Devices/Bike/tst_bike.cpp \
    Devices/BowflexT216Treadmill/tst_bowflext216treadmill.cpp \
    Devices/BowflexTreadmill/tst_bowflextreadmill.cpp \
    Devices/CSCBike/tst_cscbike.cpp \
    Devices/Chronobike/tst_chronobike.cpp \
    Devices/Concept2SkiErg/tst_concept2skierg.cpp \
    Devices/DomyosBike/tst_domyosbike.cpp \
    Devices/DomyosElliptical/tst_domyoselliptical.cpp \
    Devices/DomyosRower/tst_domyosrower.cpp \
    Devices/DomyosTreadmill/tst_domyostreadmill.cpp \
    Devices/ESLinkerTreadmill/tst_eslinkertreadmill.cpp \
    Devices/EchelonConnectSportBike/tst_echelonconnectsport.cpp \
    Devices/EchelonRower/tst_echelonrower.cpp \
    Devices/EchelonStrideTreadmill/tst_echelonstride.cpp \
    Devices/EliteRizer/tst_eliterizer.cpp \
    Devices/EliteSterzoSmart/tst_elitesterzosmart.cpp \
    Devices/Elliptical/tst_elliptical.cpp \
    Devices/FTMSBike/tst_ftmsbike.cpp \
    Devices/FTMSRower/tst_ftmsrower.cpp \
    Devices/FakeBike/tst_fakebike.cpp \
    Devices/FakeElliptical/tst_fakeelliptical.cpp \
    Devices/FitPlusBike/tst_fitplusbike.cpp \
    Devices/FitmetriaFanFit/tst_fitmetria_fanfit.cpp \
    Devices/FitshowTreadmill/tst_fitshowtreadmill.cpp \
    Devices/FlywheelBike/tst_flywheelbike.cpp \
    Devices/HeartRateBelt/tst_heartratebelt.cpp \
    Devices/HorizonGR7Bike/tst_horizongr7bike.cpp \
    Devices/HorizonTreadmill/tst_horizontreadmill.cpp \
    Devices/InspireBike/tst_inspirebike.cpp \
    Devices/KeepBike/tst_keepbike.cpp \
    Devices/KingsmithR1ProTreadmill/tst_kingsmithr1protreadmill.cpp \
    Devices/KingsmithR2Treadmill/tst_kingsmithr2treadmill.cpp \
    Devices/M3IBike/tst_m3ibike.cpp \
    Devices/MCFBike/tst_mcfbike.cpp \
    Devices/NPECableBike/tst_npecablebike.cpp \
    Devices/NautilusBike/tst_nautilusbike.cpp \
    Devices/NautilusElliptical/tst_nautiluselliptical.cpp \
    Devices/NautilusTreadmill/tst_nautilustreadmill.cpp \
    Devices/NordicTrackElliptical/tst_nordictrackelliptical.cpp \
    Devices/NordicTrackIFitADBTreadmill/tst_nordictrackifitadbtreadmill.cpp \
    Devices/OctaneTreadmill/tst_octanetreadmill.cpp \
    Devices/PafersBike/tst_pafersbike.cpp \
    Devices/PafersTreadmill/tst_paferstreadmill.cpp \
    Devices/ProFormBike/tst_proformbike.cpp \
    Devices/ProFormElliptical/tst_proformelliptical.cpp \
    Devices/ProFormEllipticalTrainer/tst_proformellipticaltrainer.cpp \
    Devices/ProFormRower/tst_proformrower.cpp \
    Devices/ProFormTreadmill/tst_proformtreadmill.cpp \
    Devices/ProFormWiFiBike/tst_proformwifibike.cpp \
    Devices/ProFormWiFiTreadmill/tst_proformwifitreadmill.cpp \
    Devices/RenphoBike/tst_renphobike.cpp \
    Devices/Rower/tst_rower.cpp \
    Devices/SchwinnIC4Bike/tst_schwinnic4bike.cpp \
    Devices/Shuaa5Treadmill/tst_shuaa5treadmill.cpp \
    Devices/SkandikaWiryBike/tst_skandikawiribike.cpp \
    Devices/SmartRowRower/tst_smartrowrower.cpp \
    Devices/SmartSpin2k/tst_smartspin2k.cpp \
    Devices/SnodeBike/tst_snodebike.cpp \
    Devices/SoleBike/tst_solebike.cpp \
    Devices/SoleElliptical/tst_soleelliptical.cpp \
    Devices/SoleF80Treadmill/tst_solef80treadmill.cpp \
    Devices/SpiritTreadmill/tst_spirittreadmill.cpp \
    Devices/SportsPlusBike/tst_sportsplusbike.cpp \
    Devices/SportsTechBike/tst_sportstechbike.cpp \
    Devices/StagesBike/tst_stagesbike.cpp \
    Devices/StrydeRunPowerSensor/tst_strydrunpowersensor.cpp \
    Devices/TacxNeo2/tst_tacxneo2.cpp \
    Devices/TechnoGymMyRunTreadmill/tst_technogymmyruntreadmill.cpp \
    Devices/TechnogymMyRunTreadmillRFComm/tst_technogymmyruntreadmillrfcomm.cpp \
    Devices/ToorxTreadmill/tst_toorxtreadmill.cpp \
    Devices/Treadmill/tst_treadmill.cpp \
    Devices/TrueTreadmill/tst_truetreadmill.cpp \
    Devices/TrxAppGateUSBBike/tst_trxappgateusbbike.cpp \
    Devices/TrxAppGateUSBTreadmill/tst_trxappgateusbtreadmill.cpp \
    Devices/UltrasportBike/tst_ultrasportbike.cpp \
    Devices/WahooKickrSnapBike/tst_wahookickrsnapbike.cpp \
    Devices/YesoulBike/tst_yesoulbike.cpp \
    Devices/iConceptBike/tst_iconceptbike.cpp



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release/ -lqdomyos-zwift
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug/ -lqdomyos-zwift
else:unix: LIBS += -L$$OUT_PWD/../src/ -lqdomyos-zwift

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/release/libqdomyos-zwift.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/debug/libqdomyos-zwift.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/release/qdomyos-zwift.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/debug/qdomyos-zwift.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../src/libqdomyos-zwift.a
