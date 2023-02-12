include(../defaults.pri)

QT += bluetooth xml location networkauth websockets widgets
QT -= gui

TEMPLATE = lib
DEFINES += QDOMYOSZWIFTLIB_LIBRARY

CONFIG += staticlib create_prl

CONFIG += c++17

INCLUDEPATH += qmdnsengine/src/include devices bluetooth android

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    android/androidactivityresultreceiver.cpp \
    bluetooth/characteristicnotifier2a37.cpp \
    bluetooth/characteristicnotifier2a53.cpp \
    bluetooth/characteristicnotifier2a5b.cpp \
    bluetooth/characteristicnotifier2a63.cpp \
    bluetooth/characteristicnotifier2acc.cpp \
    bluetooth/characteristicnotifier2acd.cpp \
    bluetooth/characteristicnotifier2ad2.cpp \
    bluetooth/characteristicnotifier2ad9.cpp \
    bluetooth/characteristicwriteprocessor.cpp \
    bluetooth/characteristicwriteprocessor2ad9.cpp \
    bluetooth/characteristicwriteprocessore005.cpp \
    devices/Computrainer.cpp \
    devices/activiotreadmill.cpp \
    devices/bhfitnesselliptical.cpp \
    devices/bike.cpp \
    devices/bluetooth.cpp \
    devices/bluetoothdevice.cpp \
    devices/bowflext216treadmill.cpp \
    devices/bowflextreadmill.cpp \
    devices/chronobike.cpp \
    devices/computrainerbike.cpp \
    devices/concept2skierg.cpp \
    devices/cscbike.cpp \
    devices/dirconmanager.cpp \
    devices/dirconpacket.cpp \
    devices/dirconprocessor.cpp \
    devices/domyosbike.cpp \
    devices/domyoselliptical.cpp \
    devices/domyosrower.cpp \
    devices/domyostreadmill.cpp \
    devices/echelonconnectsport.cpp \
    devices/echelonrower.cpp \
    devices/echelonstride.cpp \
    devices/eliterizer.cpp \
    devices/elitesterzosmart.cpp \
    devices/elliptical.cpp \
    devices/eslinkertreadmill.cpp \
    devices/fakebike.cpp \
    devices/fakeelliptical.cpp \
    devices/faketreadmill.cpp \
    devices/fitmetria_fanfit.cpp \
    devices/fitplusbike.cpp \
    devices/fitshowtreadmill.cpp \
    devices/flywheelbike.cpp \
    devices/ftmsbike.cpp \
    devices/ftmsrower.cpp \
    devices/heartratebelt.cpp \
    devices/horizongr7bike.cpp \
    devices/horizontreadmill.cpp \
    devices/iconceptbike.cpp \
    devices/inspirebike.cpp \
    devices/keepbike.cpp \
    devices/kingsmithr1protreadmill.cpp \
    devices/kingsmithr2treadmill.cpp \
    devices/lifefitnesstreadmill.cpp \
    devices/m3ibike.cpp \
    devices/mcfbike.cpp \
    devices/mepanelbike.cpp \
    devices/nautilusbike.cpp \
    devices/nautiluselliptical.cpp \
    devices/nautilustreadmill.cpp \
    devices/nordictrackelliptical.cpp \
    devices/nordictrackifitadbbike.cpp \
    devices/nordictrackifitadbtreadmill.cpp \
    devices/npecablebike.cpp \
    devices/octaneelliptical.cpp \
    devices/octanetreadmill.cpp \
    devices/pafersbike.cpp \
    devices/paferstreadmill.cpp \
    devices/proformbike.cpp \
    devices/proformelliptical.cpp \
    devices/proformellipticaltrainer.cpp \
    devices/proformrower.cpp \
    devices/proformtreadmill.cpp \
    devices/proformwifibike.cpp \
    devices/proformwifitreadmill.cpp \
    devices/renphobike.cpp \
    devices/rower.cpp \
    devices/schwinnic4bike.cpp \
    devices/shuaa5treadmill.cpp \
    devices/signalhandler.cpp \
    devices/skandikawiribike.cpp \
    devices/smartrowrower.cpp \
    devices/smartspin2k.cpp \
    devices/snodebike.cpp \
    devices/solebike.cpp \
    devices/soleelliptical.cpp \
    devices/solef80treadmill.cpp \
    devices/spirittreadmill.cpp \
    devices/sportsplusbike.cpp \
    devices/sportstechbike.cpp \
    devices/stagesbike.cpp \
    devices/strydrunpowersensor.cpp \
    devices/tacxneo2.cpp \
    devices/technogymmyruntreadmill.cpp \
    devices/technogymmyruntreadmillrfcomm.cpp \
    devices/toorxtreadmill.cpp \
    devices/treadmill.cpp \
    devices/truetreadmill.cpp \
    devices/trxappgateusbbike.cpp \
    devices/trxappgateusbtreadmill.cpp \
    devices/ultrasportbike.cpp \
    devices/virtualbike.cpp \
    devices/virtualrower.cpp \
    devices/virtualtreadmill.cpp \
    devices/wahookickrsnapbike.cpp \
    devices/yesoulbike.cpp \
    devices/pelotonbike.cpp \
    qmdnsengine/src/src/abstractserver.cpp \
    qmdnsengine/src/src/bitmap.cpp \
    qmdnsengine/src/src/browser.cpp \
    qmdnsengine/src/src/cache.cpp \
    qmdnsengine/src/src/dns.cpp \
    qmdnsengine/src/src/hostname.cpp \
    qmdnsengine/src/src/mdns.cpp \
    qmdnsengine/src/src/message.cpp \
    qmdnsengine/src/src/prober.cpp \
    qmdnsengine/src/src/provider.cpp \
    qmdnsengine/src/src/query.cpp \
    qmdnsengine/src/src/record.cpp \
    qmdnsengine/src/src/resolver.cpp \
    qmdnsengine/src/src/server.cpp \
    qmdnsengine/src/src/service.cpp \
    keepawakehelper.cpp \
    lockscreen/qzlockscreen.cpp \
    lockscreen/qzlockscreenfunctions.cpp \
    metric.cpp \
    qzsettings.cpp \
    sessionline.cpp

HEADERS += \
    android/androidactivityresultreceiver.h \
    bluetooth/characteristicnotifier.h \
    bluetooth/characteristicnotifier2a37.h \
    bluetooth/characteristicnotifier2a53.h \
    bluetooth/characteristicnotifier2a5b.h \
    bluetooth/characteristicnotifier2a63.h \
    bluetooth/characteristicnotifier2acc.h \
    bluetooth/characteristicnotifier2acd.h \
    bluetooth/characteristicnotifier2ad2.h \
    bluetooth/characteristicnotifier2ad9.h \
    bluetooth/characteristicwriteprocessor.h \
    bluetooth/characteristicwriteprocessor2ad9.h \
    bluetooth/characteristicwriteprocessore005.h \
    devices/Computrainer.h \
    devices/activiotreadmill.h \
    devices/bhfitnesselliptical.h \
    devices/bike.h \
    devices/bluetooth.h \
    devices/bluetoothdevice.h \
    devices/bowflext216treadmill.h \
    devices/bowflextreadmill.h \
    devices/chronobike.h \
    devices/computrainerbike.h \
    devices/concept2skierg.h \
    devices/cscbike.h \
    devices/dirconmanager.h \
    devices/dirconpacket.h \
    devices/dirconprocessor.h \
    devices/domyosbike.h \
    devices/domyoselliptical.h \
    devices/domyosrower.h \
    devices/domyostreadmill.h \
    devices/echelonconnectsport.h \
    devices/echelonrower.h \
    devices/echelonstride.h \
    devices/eliterizer.h \
    devices/elitesterzosmart.h \
    devices/elliptical.h \
    devices/eslinkertreadmill.h \
    devices/fakebike.h \
    devices/fakeelliptical.h \
    devices/faketreadmill.h \
    devices/fitmetria_fanfit.h \
    devices/fitplusbike.h \
    devices/fitshowtreadmill.h \
    devices/flywheelbike.h \
    devices/ftmsbike.h \
    devices/ftmsrower.h \
    devices/heartratebelt.h \
    devices/horizongr7bike.h \
    devices/horizontreadmill.h \
    devices/iconceptbike.h \
    devices/inspirebike.h \
    devices/keepbike.h \
    devices/kingsmithr1protreadmill.h \
    devices/kingsmithr2treadmill.h \
    devices/lifefitnesstreadmill.h \
    devices/m3ibike.h \
    devices/mcfbike.h \
    devices/mepanelbike.h \
    devices/nautilusbike.h \
    devices/nautiluselliptical.h \
    devices/nautilustreadmill.h \
    devices/nordictrackelliptical.h \
    devices/nordictrackifitadbbike.h \
    devices/nordictrackifitadbtreadmill.h \
    devices/npecablebike.h \
    devices/octaneelliptical.h \
    devices/octanetreadmill.h \
    devices/pafersbike.h \
    devices/paferstreadmill.h \
    devices/proformbike.h \
    devices/proformelliptical.h \
    devices/proformellipticaltrainer.h \
    devices/proformrower.h \
    devices/proformtreadmill.h \
    devices/proformwifibike.h \
    devices/proformwifitreadmill.h \
    devices/renphobike.h \
    devices/rower.h \
    devices/schwinnic4bike.h \
    devices/shuaa5treadmill.h \
    devices/signalhandler.h \
    devices/skandikawiribike.h \
    devices/smartrowrower.h \
    devices/smartspin2k.h \
    devices/snodebike.h \
    devices/solebike.h \
    devices/soleelliptical.h \
    devices/solef80treadmill.h \
    devices/spirittreadmill.h \
    devices/sportsplusbike.h \
    devices/sportstechbike.h \
    devices/stagesbike.h \
    devices/strydrunpowersensor.h \
    devices/tacxneo2.h \
    devices/technogymmyruntreadmill.h \
    devices/technogymmyruntreadmillrfcomm.h \
    devices/toorxtreadmill.h \
    devices/treadmill.h \
    devices/truetreadmill.h \
    devices/trxappgateusbbike.h \
    devices/trxappgateusbtreadmill.h \
    devices/ultrasportbike.h \
    devices/virtualbike.h \
    devices/virtualrower.h \
    devices/virtualtreadmill.h \
    devices/wahookickrsnapbike.h \
    devices/yesoulbike.h \
    definitions.h \
    devices/pelotonbike.h \
    qmdnsengine/src/include/qmdnsengine/abstractserver.h \
    qmdnsengine/src/include/qmdnsengine/bitmap.h \
    qmdnsengine/src/include/qmdnsengine/browser.h \
    qmdnsengine/src/include/qmdnsengine/cache.h \
    qmdnsengine/src/include/qmdnsengine/dns.h \
    qmdnsengine/src/include/qmdnsengine/hostname.h \
    qmdnsengine/src/include/qmdnsengine/mdns.h \
    qmdnsengine/src/include/qmdnsengine/message.h \
    qmdnsengine/src/include/qmdnsengine/prober.h \
    qmdnsengine/src/include/qmdnsengine/provider.h \
    qmdnsengine/src/include/qmdnsengine/query.h \
    qmdnsengine/src/include/qmdnsengine/record.h \
    qmdnsengine/src/include/qmdnsengine/resolver.h \
    qmdnsengine/src/include/qmdnsengine/server.h \
    qmdnsengine/src/include/qmdnsengine/service.h \
    qmdnsengine/src/src/bitmap_p.h \
    qmdnsengine/src/src/browser_p.h \
    qmdnsengine/src/src/cache_p.h \
    qmdnsengine/src/src/hostname_p.h \
    qmdnsengine/src/src/message_p.h \
    qmdnsengine/src/src/prober_p.h \
    qmdnsengine/src/src/provider_p.h \
    qmdnsengine/src/src/query_p.h \
    qmdnsengine/src/src/record_p.h \
    qmdnsengine/src/src/resolver_p.h \
    qmdnsengine/src/src/server_p.h \
    qmdnsengine/src/src/service_p.h \
    keepawakehelper.h \
    lockscreen/qzlockscreen.h \
    lockscreen/qzlockscreenfunctions.h \
    metric.h \
    qdebugfixup.h \
    qmdnsengine_export.h \
    qzsettings.h \
    sessionline.h


# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

include(../version.pri)
