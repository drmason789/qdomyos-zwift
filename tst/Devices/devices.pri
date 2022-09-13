include(../qdomyos-zwift-tests.pri)


#include the main library

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../src/release/ -lqdomyos-zwift
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../src/debug/ -lqdomyos-zwift
else:unix: LIBS += -L$$OUT_PWD/../../../src/ -lqdomyos-zwift

INCLUDEPATH += $$PWD/../../../src
DEPENDPATH += $$PWD/../../../src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../src/release/libqdomyos-zwift.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../src/debug/libqdomyos-zwift.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../src/release/qdomyos-zwift.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../src/debug/qdomyos-zwift.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../src/libqdomyos-zwift.a
#end of main lbrary


#Include the common functionality
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Common/release/ -lCommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Common/debug/ -lCommon
else:unix: LIBS += -L$$OUT_PWD/../../Common/ -lCommon

INCLUDEPATH += $$PWD/../Common
DEPENDPATH += $$PWD/../Common

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/release/libCommon.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/debug/libCommon.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/release/Common.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/debug/Common.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Common/libCommon.a
#end of common functionality
