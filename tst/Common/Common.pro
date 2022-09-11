QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase staticlib
CONFIG -= app_bundle

TEMPLATE = lib

SOURCES +=  tst_bluetoothdevice.cpp

HEADERS += \
    tst_bluetoothdevice.h

include(../qdomyos-zwift-tests.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../src/release/ -lqdomyos-zwift
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../src/debug/ -lqdomyos-zwift
else:unix: LIBS += -L$$OUT_PWD/../../../src/ -lqdomyos-zwift
