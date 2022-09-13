QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase staticlib
CONFIG -= app_bundle
DEFINES += LIB_LIBRARY

TEMPLATE = lib

SOURCES +=  tst_bluetoothdevice.cpp

HEADERS += \
    tst_bluetoothdevice.h

include(../qdomyos-zwift-tests.pri)


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../src/release/ -lqdomyos-zwift
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../src/debug/ -lqdomyos-zwift
else:unix: LIBS += -L$$OUT_PWD/../../src/ -lqdomyos-zwift

INCLUDEPATH += $$PWD/../../src
DEPENDPATH += $$PWD/../../src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/release/libqdomyos-zwift.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/debug/libqdomyos-zwift.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/release/qdomyos-zwift.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../src/debug/qdomyos-zwift.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../src/libqdomyos-zwift.a
