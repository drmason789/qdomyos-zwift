QT += bluetooth location networkauth
QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

INCLUDEPATH += qmdnsengine/src/include

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bluetooth/characteristicnotifier2a37.cpp \
    Bluetooth/characteristicnotifier2a53.cpp \
    Bluetooth/characteristicnotifier2a5b.cpp \
    Bluetooth/characteristicnotifier2a63.cpp \
    Bluetooth/characteristicnotifier2acc.cpp \
    Bluetooth/characteristicnotifier2acd.cpp \
    Bluetooth/characteristicnotifier2ad2.cpp \
    Bluetooth/characteristicnotifier2ad9.cpp \
    Bluetooth/characteristicwriteprocessor.cpp \
    Bluetooth/characteristicwriteprocessor2ad9.cpp \
    Bluetooth/characteristicwriteprocessore005.cpp \
    Devices/Computrainer.cpp \
    Devices/activiotreadmill.cpp \
    Devices/bhfitnesselliptical.cpp \
    Devices/bike.cpp \
    Devices/bluetooth.cpp \
    Devices/bluetoothdevice.cpp \
    Devices/bowflext216treadmill.cpp \
    Devices/bowflextreadmill.cpp \
    Devices/chronobike.cpp \
    Devices/computrainerbike.cpp \
    Devices/concept2skierg.cpp \
    Devices/cscbike.cpp \
    Devices/dirconmanager.cpp \
    Devices/dirconpacket.cpp \
    Devices/dirconprocessor.cpp \
    Devices/domyosbike.cpp \
    Devices/domyoselliptical.cpp \
    Devices/domyosrower.cpp \
    Devices/domyostreadmill.cpp \
    Devices/echelonconnectsport.cpp \
    Devices/echelonrower.cpp \
    Devices/echelonstride.cpp \
    Devices/eliterizer.cpp \
    Devices/elitesterzosmart.cpp \
    Devices/elliptical.cpp \
    Devices/eslinkertreadmill.cpp \
    Devices/fakebike.cpp \
    Devices/fakeelliptical.cpp \
    Devices/faketreadmill.cpp \
    Devices/fitmetria_fanfit.cpp \
    Devices/fitplusbike.cpp \
    Devices/fitshowtreadmill.cpp \
    Devices/flywheelbike.cpp \
    Devices/ftmsbike.cpp \
    Devices/ftmsrower.cpp \
    Devices/heartratebelt.cpp \
    Devices/horizongr7bike.cpp \
    Devices/horizontreadmill.cpp \
    Devices/iconceptbike.cpp \
    Devices/inspirebike.cpp \
    Devices/keepbike.cpp \
    Devices/kingsmithr1protreadmill.cpp \
    Devices/kingsmithr2treadmill.cpp \
    Devices/lifefitnesstreadmill.cpp \
    Devices/m3ibike.cpp \
    Devices/mcfbike.cpp \
    Devices/mepanelbike.cpp \
    Devices/nautilusbike.cpp \
    Devices/nautiluselliptical.cpp \
    Devices/nautilustreadmill.cpp \
    Devices/nordictrackelliptical.cpp \
    Devices/nordictrackifitadbbike.cpp \
    Devices/nordictrackifitadbtreadmill.cpp \
    Devices/npecablebike.cpp \
    Devices/octaneelliptical.cpp \
    Devices/octanetreadmill.cpp \
    Devices/pafersbike.cpp \
    Devices/paferstreadmill.cpp \
    Devices/proformbike.cpp \
    Devices/proformelliptical.cpp \
    Devices/proformellipticaltrainer.cpp \
    Devices/proformrower.cpp \
    Devices/proformtreadmill.cpp \
    Devices/proformwifibike.cpp \
    Devices/proformwifitreadmill.cpp \
    Devices/renphobike.cpp \
    Devices/rower.cpp \
    Devices/schwinnic4bike.cpp \
    Devices/shuaa5treadmill.cpp \
    Devices/signalhandler.cpp \
    Devices/skandikawiribike.cpp \
    Devices/smartrowrower.cpp \
    Devices/smartspin2k.cpp \
    Devices/snodebike.cpp \
    Devices/solebike.cpp \
    Devices/soleelliptical.cpp \
    Devices/solef80treadmill.cpp \
    Devices/spirittreadmill.cpp \
    Devices/sportsplusbike.cpp \
    Devices/sportstechbike.cpp \
    Devices/stagesbike.cpp \
    Devices/strydrunpowersensor.cpp \
    Devices/tacxneo2.cpp \
    Devices/tcpclientinfosender.cpp \
    Devices/technogymmyruntreadmill.cpp \
    Devices/technogymmyruntreadmillrfcomm.cpp \
    Devices/toorxtreadmill.cpp \
    Devices/treadmill.cpp \
    Devices/truetreadmill.cpp \
    Devices/trxappgateusbbike.cpp \
    Devices/trxappgateusbtreadmill.cpp \
    Devices/ultrasportbike.cpp \
    Devices/virtualbike.cpp \
    Devices/virtualrower.cpp \
    Devices/virtualtreadmill.cpp \
    Devices/wahookickrsnapbike.cpp \
    Devices/yesoulbike.cpp \
    keepawakehelper.cpp \
    metric.cpp \
    qzsettings.cpp \
    sessionline.cpp

HEADERS += \
    Bluetooth/characteristicnotifier.h \
    Bluetooth/characteristicnotifier2a37.h \
    Bluetooth/characteristicnotifier2a53.h \
    Bluetooth/characteristicnotifier2a5b.h \
    Bluetooth/characteristicnotifier2a63.h \
    Bluetooth/characteristicnotifier2acc.h \
    Bluetooth/characteristicnotifier2acd.h \
    Bluetooth/characteristicnotifier2ad2.h \
    Bluetooth/characteristicnotifier2ad9.h \
    Bluetooth/characteristicwriteprocessor.h \
    Bluetooth/characteristicwriteprocessor2ad9.h \
    Bluetooth/characteristicwriteprocessore005.h \
    Devices/Computrainer.h \
    Devices/activiotreadmill.h \
    Devices/bhfitnesselliptical.h \
    Devices/bike.h \
    Devices/bluetooth.h \
    Devices/bluetoothdevice.h \
    Devices/bowflext216treadmill.h \
    Devices/bowflextreadmill.h \
    Devices/chronobike.h \
    Devices/computrainerbike.h \
    Devices/concept2skierg.h \
    Devices/cscbike.h \
    Devices/dirconmanager.h \
    Devices/dirconpacket.h \
    Devices/dirconprocessor.h \
    Devices/domyosbike.h \
    Devices/domyoselliptical.h \
    Devices/domyosrower.h \
    Devices/domyostreadmill.h \
    Devices/echelonconnectsport.h \
    Devices/echelonrower.h \
    Devices/echelonstride.h \
    Devices/eliterizer.h \
    Devices/elitesterzosmart.h \
    Devices/elliptical.h \
    Devices/eslinkertreadmill.h \
    Devices/fakebike.h \
    Devices/fakeelliptical.h \
    Devices/faketreadmill.h \
    Devices/fitmetria_fanfit.h \
    Devices/fitplusbike.h \
    Devices/fitshowtreadmill.h \
    Devices/flywheelbike.h \
    Devices/ftmsbike.h \
    Devices/ftmsrower.h \
    Devices/heartratebelt.h \
    Devices/horizongr7bike.h \
    Devices/horizontreadmill.h \
    Devices/iconceptbike.h \
    Devices/inspirebike.h \
    Devices/keepbike.h \
    Devices/kingsmithr1protreadmill.h \
    Devices/kingsmithr2treadmill.h \
    Devices/lifefitnesstreadmill.h \
    Devices/m3ibike.h \
    Devices/mcfbike.h \
    Devices/mepanelbike.h \
    Devices/nautilusbike.h \
    Devices/nautiluselliptical.h \
    Devices/nautilustreadmill.h \
    Devices/nordictrackelliptical.h \
    Devices/nordictrackifitadbbike.h \
    Devices/nordictrackifitadbtreadmill.h \
    Devices/npecablebike.h \
    Devices/octaneelliptical.h \
    Devices/octanetreadmill.h \
    Devices/pafersbike.h \
    Devices/paferstreadmill.h \
    Devices/proformbike.h \
    Devices/proformelliptical.h \
    Devices/proformellipticaltrainer.h \
    Devices/proformrower.h \
    Devices/proformtreadmill.h \
    Devices/proformwifibike.h \
    Devices/proformwifitreadmill.h \
    Devices/renphobike.h \
    Devices/rower.h \
    Devices/schwinnic4bike.h \
    Devices/shuaa5treadmill.h \
    Devices/signalhandler.h \
    Devices/skandikawiribike.h \
    Devices/smartrowrower.h \
    Devices/smartspin2k.h \
    Devices/snodebike.h \
    Devices/solebike.h \
    Devices/soleelliptical.h \
    Devices/solef80treadmill.h \
    Devices/spirittreadmill.h \
    Devices/sportsplusbike.h \
    Devices/sportstechbike.h \
    Devices/stagesbike.h \
    Devices/strydrunpowersensor.h \
    Devices/tacxneo2.h \
    Devices/tcpclientinfosender.h \
    Devices/technogymmyruntreadmill.h \
    Devices/technogymmyruntreadmillrfcomm.h \
    Devices/toorxtreadmill.h \
    Devices/treadmill.h \
    Devices/truetreadmill.h \
    Devices/trxappgateusbbike.h \
    Devices/trxappgateusbtreadmill.h \
    Devices/ultrasportbike.h \
    Devices/virtualbike.h \
    Devices/virtualrower.h \
    Devices/virtualtreadmill.h \
    Devices/wahookickrsnapbike.h \
    Devices/yesoulbike.h \
    definitions.h \
    keepawakehelper.h \
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
