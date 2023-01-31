
#include <qglobal.h>
#include "qzlockscreen.h"
#include "defaultlockscreenfunctions.h"
#include "qzsettings.h"


#ifdef Q_OS_IOS
#ifndef IO_UNDER_QT
#include "ios/ioslockscreenfunctions.h"
#endif
#endif

bool QZLockscreenFunctions::isPelotonWorkaroundActive() { return false; }

QZLockscreenFunctions *QZLockscreenFunctions::create(){
#ifdef Q_OS_IOS
#ifndef IO_UNDER_QT
    return new IOSLockscreenFunctions();
#endif
#endif
    return new DefaultLockscreenFunctions();
}
