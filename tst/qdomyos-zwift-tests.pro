GOOGLETEST_DIR = $$PWD/googletest

include(../defaults.pri)
include(gtest_dependency.pri)

TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += androidextras

SOURCES += \
        Devices/bluetoothsignalreceiver.cpp \
        Devices/devicediscoveryinfo.cpp \
        Devices/devicenamepatterngroup.cpp \
        Devices/productindex.cpp \
        Devices/producttestdata.cpp \
        Devices/producttestdatabuilder.cpp \
        Devices/producttestdataindex.cpp \
        Devices/producttestsuite.cpp \
        Devices/typeidgenerator.cpp \
        Erg/ergtabletestsuite.cpp \
        ToolTests/testsettingstestsuite.cpp \
        Tools/testsettings.cpp \
        main.cpp

# Avoid the "File too big" error building in Windows. This has happened when a template class is used with Google Test / typed tests
# to produce a large number of classes.
win32:QMAKE_CXXFLAGS += -Wa,-mbig-obj

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release/ -lqdomyos-zwift
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug/ -lqdomyos-zwift
else:unix: LIBS += -L$$OUT_PWD/../src/ -lqdomyos-zwift

INCLUDEPATH += $$PWD/../src $$PWD/../src/devices
DEPENDPATH += $$PWD/../src $$PWD/../src/devices

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/release/libqdomyos-zwift.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/debug/libqdomyos-zwift.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/release/qdomyos-zwift.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/debug/qdomyos-zwift.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../src/libqdomyos-zwift.a

HEADERS += \
    Devices/bluetoothsignalreceiver.h \
    Devices/devicediscoveryinfo.h \
    Devices/devicenamepatterngroup.h \
    Devices/devicetypeid.h \
    Devices/productindex.h \
    Devices/producttestdata.h \
    Devices/producttestdatabuilder.h \
    Devices/producttestdataindex.h \
    Devices/producttestsuite.h \
    Devices/typeidgenerator.h \
    Erg/ergtabletestsuite.h \
    ToolTests/testsettingstestsuite.h \
    Tools/testsettings.h
