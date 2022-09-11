include(../qdomyos-zwift-tests.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../src/release/ -lqdomyos-zwift2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../src/debug/ -lqdomyos-zwift2
else:unix: LIBS += -L$$OUT_PWD/../../../src/ -lqdomyos-zwift2
