include(../defaults.pri)
QT += bluetooth widgets xml positioning quick networkauth websockets texttospeech location multimedia
QTPLUGIN += qavfmediaplayer
QT+= charts

qtHaveModule(httpserver) {
    QT += httpserver
    DEFINES += Q_HTTPSERVER
    SOURCES += webserverinfosender.cpp
    HEADERS += webserverinfosender.h

    # android and iOS are using ChartJS
    unix:android: {
        QT+= webview
        DEFINES += CHARTJS
    }
    ios: {
        QT+= webview
        DEFINES += CHARTJS
    }
#	 win32: {
#	     DEFINES += CHARTJS
#		}
}

CONFIG += c++17 console app_bundle optimize_full ltcg

CONFIG += qmltypes

#win32: CONFIG += webengine
#unix:!android: CONFIG += webengine

QML_IMPORT_NAME = org.cagnulein.qdomyoszwift
QML_IMPORT_MAJOR_VERSION = 1
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

win32:QMAKE_LFLAGS_DEBUG += -static-libstdc++ -static-libgcc
win32:QMAKE_LFLAGS_RELEASE += -static-libstdc++ -static-libgcc

QMAKE_LFLAGS_RELEASE += -s
QMAKE_CXXFLAGS += -fno-sized-deallocation
unix:android: {
    CONFIG -= optimize_size
    QMAKE_CFLAGS_OPTIMIZE_FULL -= -Oz
    QMAKE_CFLAGS_OPTIMIZE_FULL += -O3
}
macx: CONFIG += debug
win32: CONFIG += debug
macx: CONFIG += static
macx {
    QMAKE_INFO_PLIST = macx/Info.plist
}
INCLUDEPATH += qmdnsengine/src/include

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS IO_UNDER_QT SMTP_BUILD NOMINMAX


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# include(../qtzeroconf/qtzeroconf.pri)

SOURCES += \
    $$PWD/QTelnet.cpp \
   $$PWD/bkoolbike.cpp \
   $$PWD/csafe.cpp \
   $$PWD/csaferower.cpp \
    $$PWD/eliteariafan.cpp \
   $$PWD/fakerower.cpp \
    $$PWD/proformtelnetbike.cpp \
    $$PWD/virtualdevice.cpp \
    $$PWD/androidactivityresultreceiver.cpp \
    $$PWD/androidadblog.cpp \
   $$PWD/apexbike.cpp \
    $$PWD/handleurl.cpp \
   $$PWD/iconceptelliptical.cpp \
    $$PWD/localipaddress.cpp \
   $$PWD/pelotonbike.cpp \
   $$PWD/schwinn170bike.cpp \
   $$PWD/wahookickrheadwind.cpp \
   $$PWD/windows_zwift_workout_paddleocr_thread.cpp \
   $$PWD/ypooelliptical.cpp \
   $$PWD/ziprotreadmill.cpp \
    $$PWD/zwift_play/zwiftclickremote.cpp \
   Computrainer.cpp \
   PathController.cpp \
    characteristicnotifier2a53.cpp \
    characteristicnotifier2a5b.cpp \
    characteristicnotifier2acc.cpp \
    characteristicnotifier2acd.cpp \
    characteristicnotifier2ad9.cpp \
   characteristicwriteprocessor.cpp \
   characteristicwriteprocessore005.cpp \
   computrainerbike.cpp \
    fakeelliptical.cpp \
   faketreadmill.cpp \
   lifefitnesstreadmill.cpp \
   mepanelbike.cpp \
   nautilusbike.cpp \
    nordictrackelliptical.cpp \
    nordictrackifitadbbike.cpp \
   nordictrackifitadbtreadmill.cpp \
   octaneelliptical.cpp \
   octanetreadmill.cpp \
   proformellipticaltrainer.cpp \
   proformrower.cpp \
   proformwifibike.cpp \
   proformwifitreadmill.cpp \
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
    activiotreadmill.cpp \
   bhfitnesselliptical.cpp \
   bike.cpp \
	     bluetooth.cpp \
		bluetoothdevice.cpp \
    characteristicnotifier2a37.cpp \
    characteristicnotifier2a63.cpp \
    characteristicnotifier2ad2.cpp \
    characteristicwriteprocessor2ad9.cpp \
   bowflext216treadmill.cpp \
    bowflextreadmill.cpp \
   chronobike.cpp \
    concept2skierg.cpp \
   cscbike.cpp \
    dirconmanager.cpp \
    dirconpacket.cpp \
    dirconprocessor.cpp \
	 domyoselliptical.cpp \
   domyosrower.cpp \
	     domyostreadmill.cpp \
		echelonconnectsport.cpp \
   echelonrower.cpp \
   echelonstride.cpp \
   eliterizer.cpp \
   elitesterzosmart.cpp \
	 elliptical.cpp \
	eslinkertreadmill.cpp \
    fakebike.cpp \
   filedownloader.cpp \
    fitmetria_fanfit.cpp \
   fitplusbike.cpp \
	fitshowtreadmill.cpp \
	flywheelbike.cpp \
	ftmsbike.cpp \
    ftmsrower.cpp \
	     gpx.cpp \
		heartratebelt.cpp \
   homefitnessbuddy.cpp \
	homeform.cpp \
    horizongr7bike.cpp \
   horizontreadmill.cpp \
   iconceptbike.cpp \
	inspirebike.cpp \
	keepawakehelper.cpp \
   keepbike.cpp \
   kingsmithr1protreadmill.cpp \
   kingsmithr2treadmill.cpp \
	     main.cpp \
   mcfbike.cpp \
		metric.cpp \
   nautiluselliptical.cpp \
    nautilustreadmill.cpp \
    npecablebike.cpp \
   pafersbike.cpp \
   paferstreadmill.cpp \
   peloton.cpp \
   powerzonepack.cpp \
	proformbike.cpp \
   proformelliptical.cpp \
	proformtreadmill.cpp \
	qfit.cpp \
    qzsettings.cpp \
   renphobike.cpp \
   rower.cpp \
	schwinnic4bike.cpp \
   screencapture.cpp \
	sessionline.cpp \
   shuaa5treadmill.cpp \
	signalhandler.cpp \
   simplecrypt.cpp \
    skandikawiribike.cpp \
   smartrowrower.cpp \
   smartspin2k.cpp \
    smtpclient/src/emailaddress.cpp \
    smtpclient/src/mimeattachment.cpp \
    smtpclient/src/mimecontentformatter.cpp \
    smtpclient/src/mimefile.cpp \
    smtpclient/src/mimehtml.cpp \
    smtpclient/src/mimeinlinefile.cpp \
    smtpclient/src/mimemessage.cpp \
    smtpclient/src/mimemultipart.cpp \
    smtpclient/src/mimepart.cpp \
    smtpclient/src/mimetext.cpp \
    smtpclient/src/quotedprintable.cpp \
    smtpclient/src/smtpclient.cpp \
   snodebike.cpp \
   solebike.cpp \
   soleelliptical.cpp \
   solef80treadmill.cpp \
   spirittreadmill.cpp \
   sportsplusbike.cpp \
   sportstechbike.cpp \
   strydrunpowersensor.cpp \
   tacxneo2.cpp \
    tcpclientinfosender.cpp \
   technogymmyruntreadmill.cpp \
    technogymmyruntreadmillrfcomm.cpp \
    templateinfosender.cpp \
    templateinfosenderbuilder.cpp \
   stagesbike.cpp \
	     toorxtreadmill.cpp \
		  treadmill.cpp \
   truetreadmill.cpp \
   trxappgateusbbike.cpp \
   ultrasportbike.cpp \
   virtualrower.cpp \
   wahookickrsnapbike.cpp \
		yesoulbike.cpp \
		  trainprogram.cpp \
		trxappgateusbtreadmill.cpp \
	 virtualbike.cpp \
	     virtualtreadmill.cpp \
             m3ibike.cpp \
                domyosbike.cpp \
               scanrecordresult.cpp \
					windows_zwift_incline_paddleocr_thread.cpp \
   zwiftworkout.cpp
macx: SOURCES += macos/lockscreen.mm
!ios: SOURCES += mainwindow.cpp charts.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += fit-sdk/

HEADERS += \
    $$PWD/QTelnet.h \
   $$PWD/bkoolbike.h \
   $$PWD/csafe.h \
   $$PWD/csaferower.h \
    $$PWD/eliteariafan.h \
    $$PWD/proformtelnetbike.h \
   $$PWD/windows_zwift_workout_paddleocr_thread.h \
   $$PWD/fakerower.h \
    $$PWD/zwift-api/PlayerStateWrapper.h \
    $$PWD/zwift-api/zwift_client_auth.h \
    $$PWD/zwift_play/abstractZapDevice.h \
    $$PWD/zwift_play/zapBleUuids.h \
    $$PWD/zwift_play/zapConstants.h \
    $$PWD/zwift_play/zwiftPlayDevice.h \
    $$PWD/zwift_play/zwiftclickremote.h \
    virtualdevice.h \
    $$PWD/androidactivityresultreceiver.h \
    $$PWD/androidadblog.h \
   $$PWD/apexbike.h \
    $$PWD/discoveryoptions.h \
    $$PWD/handleurl.h \
   $$PWD/iconceptelliptical.h \
    $$PWD/localipaddress.h \
   $$PWD/pelotonbike.h \
   $$PWD/schwinn170bike.h \
   $$PWD/wahookickrheadwind.h \
   $$PWD/ypooelliptical.h \
   $$PWD/ziprotreadmill.h \
   Computrainer.h \
   PathController.h \
    characteristicnotifier2a53.h \
    characteristicnotifier2a5b.h \
    characteristicnotifier2acc.h \
    characteristicnotifier2acd.h \
    characteristicnotifier2ad9.h \
   characteristicwriteprocessore005.h \
   computrainerbike.h \
    definitions.h \
    fakeelliptical.h \
   faketreadmill.h \
   lifefitnesstreadmill.h \
   mepanelbike.h \
   nautilusbike.h \
    nordictrackelliptical.h \
    nordictrackifitadbbike.h \
   nordictrackifitadbtreadmill.h \
   octaneelliptical.h \
   octanetreadmill.h \
   proformellipticaltrainer.h \
   proformrower.h \
   proformwifibike.h \
   proformwifitreadmill.h \
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
    activiotreadmill.h \
   bhfitnesselliptical.h \
   bike.h \
	bluetooth.h \
	bluetoothdevice.h \
    characteristicnotifier.h \
    characteristicnotifier2a37.h \
    characteristicnotifier2a63.h \
    characteristicnotifier2ad2.h \
    characteristicwriteprocessor.h \
    characteristicwriteprocessor2ad9.h \
   bowflext216treadmill.h \
    bowflextreadmill.h \
   chronobike.h \
    concept2skierg.h \
   cscbike.h \
    dirconmanager.h \
    dirconpacket.h \
    dirconprocessor.h \
	 domyoselliptical.h \
   domyosrower.h \
	domyostreadmill.h \
	echelonconnectsport.h \
   echelonrower.h \
   echelonstride.h \
   eliterizer.h \
   elitesterzosmart.h \
	 elliptical.h \
   eslinkertreadmill.h \
    fakebike.h \
   filedownloader.h \
    fitmetria_fanfit.h \
   fitplusbike.h \
    ftmsrower.h \
   homefitnessbuddy.h \
    horizongr7bike.h \
   iconceptbike.h \
   keepbike.h \
   kingsmithr1protreadmill.h \
   kingsmithr2treadmill.h \
   m3ibike.h \
        fitshowtreadmill.h \	
	flywheelbike.h \
	ftmsbike.h \
	 heartratebelt.h \
	homeform.h \
   horizontreadmill.h \
	inspirebike.h \
	ios/lockscreen.h \
	keepawakehelper.h \
	macos/lockscreen.h \
        ios/M3iIOS-Interface.h \
	material.h \
   mcfbike.h \
	metric.h \
   nautiluselliptical.h \
    nautilustreadmill.h \
    npecablebike.h \
   pafersbike.h \
   paferstreadmill.h \
   peloton.h \
   powerzonepack.h \
	proformbike.h \
   proformelliptical.h \
	proformtreadmill.h \
    qdebugfixup.h \
	qfit.h \
    qmdnsengine_export.h \
    qzsettings.h \
   renphobike.h \
   rower.h \
	schwinnic4bike.h \
   screencapture.h \
	sessionline.h \
   shuaa5treadmill.h \
	signalhandler.h \
   simplecrypt.h \
    skandikawiribike.h \
   smartrowrower.h \
   smartspin2k.h \
    smtpclient/src/SmtpMime \
    smtpclient/src/emailaddress.h \
    smtpclient/src/mimeattachment.h \
    smtpclient/src/mimecontentformatter.h \
    smtpclient/src/mimefile.h \
    smtpclient/src/mimehtml.h \
    smtpclient/src/mimeinlinefile.h \
    smtpclient/src/mimemessage.h \
    smtpclient/src/mimemultipart.h \
    smtpclient/src/mimepart.h \
    smtpclient/src/mimetext.h \
    smtpclient/src/quotedprintable.h \
    smtpclient/src/smtpclient.h \
    smtpclient/src/smtpexports.h \
   snodebike.h \
   solebike.h \
   soleelliptical.h \
   solef80treadmill.h \
   spirittreadmill.h \
   sportsplusbike.h \
   sportstechbike.h \
   strydrunpowersensor.h \
   tacxneo2.h \
    tcpclientinfosender.h \
   technogymmyruntreadmill.h \
    technogymmyruntreadmillrfcomm.h \
    templateinfosender.h \
    templateinfosenderbuilder.h \
   stagesbike.h \
	toorxtreadmill.h \
	gpx.h \
	treadmill.h \
	mainwindow.h \
	trainprogram.h \
   truetreadmill.h \
   trxappgateusbbike.h \
	trxappgateusbtreadmill.h \
   ultrasportbike.h \
	 virtualbike.h \
   virtualrower.h \
	virtualtreadmill.h \
	 domyosbike.h \
   wahookickrsnapbike.h \
   wobjectdefs.h \
   wobjectimpl.h \
        yesoulbike.h \
        scanrecordresult.h \
		  windows_zwift_incline_paddleocr_thread.h \
   zwiftworkout.h


exists(secret.h): HEADERS += secret.h

!ios: HEADERS += charts.h

!ios: FORMS += \
   charts.ui \
	mainwindow.ui

RESOURCES += \
   icons.qrc \
	qml.qrc

DISTFILES += \
    $$PWD/android/libs/android_antlib_4-16-0.aar \
    $$PWD/android/libs/connectiq-mobile-sdk-android-1.5.aar \
    $$PWD/android/libs/zaplibrary-debug.aar \
    $$PWD/android/res/xml/device_filter.xml \
   $$PWD/android/src/CSafeRowerUSBHID.java \
    $$PWD/android/src/ContentHelper.java \
    $$PWD/android/src/Garmin.java \
   $$PWD/android/src/HidBridge.java \
    $$PWD/android/src/IQMessageReceiverWrapper.java \
    $$PWD/android/src/MediaProjection.java \
    $$PWD/android/src/NotificationUtils.java \
    $$PWD/android/src/ScreenCaptureService.java \
    $$PWD/android/src/WearableController.java \
    $$PWD/android/src/WearableMessageListenerService.java \
    $$PWD/android/src/ZapClickLayer.java \
    $$PWD/android/src/ZwiftAPI.java \
    $$PWD/android/src/main/proto/zwift_messages.proto \
    .clang-format \
   AppxManifest.xml \
   android/AndroidManifest.xml \
	android/build.gradle \
	android/gradle/wrapper/gradle-wrapper.jar \
	android/gradle/wrapper/gradle-wrapper.properties \
	android/gradlew \
	android/gradlew.bat \
   android/res/layout/floating_layout.xml \
	android/res/values/libs.xml \
	android/src/Ant.java \
	android/src/ChannelService.java \
   android/src/FloatingHandler.java \
   android/src/FloatingWindowGFG.java \
   android/src/ForegroundService.java \
   android/src/NotificationClient.java \
   android/src/QZAdbRemote.java \
        android/src/ScanRecordResult.java \
        android/src/NativeScanCallback.java \
   android/src/HeartChannelController.java \
	android/src/MyActivity.java \
	android/src/PowerChannelController.java \
	android/src/SpeedChannelController.java \
   android/src/SDMChannelController.java \
    android/src/Usbserial.java \
   android/src/com/cgutman/adblib/AdbBase64.java \
   android/src/com/cgutman/adblib/AdbConnection.java \
   android/src/com/cgutman/adblib/AdbCrypto.java \
   android/src/com/cgutman/adblib/AdbProtocol.java \
   android/src/com/cgutman/adblib/AdbStream.java \
   android/src/com/cgutman/adblib/package-info.java \
   android/src/com/cgutman/androidremotedebugger/AdbUtils.java \
   android/src/com/cgutman/androidremotedebugger/adblib/AndroidBase64.java \
   android/src/com/cgutman/androidremotedebugger/console/CommandHistory.java \
   android/src/com/cgutman/androidremotedebugger/console/ConsoleBuffer.java \
   android/src/com/cgutman/androidremotedebugger/devconn/DeviceConnection.java \
   android/src/com/cgutman/androidremotedebugger/devconn/DeviceConnectionListener.java \
   android/src/com/cgutman/androidremotedebugger/service/ShellListener.java \
   android/src/com/cgutman/androidremotedebugger/service/ShellService.java \
   android/src/com/cgutman/androidremotedebugger/ui/Dialog.java \
   android/src/com/cgutman/androidremotedebugger/ui/SpinnerDialog.java \
	android/src/com/dsi/ant/channel/PredefinedNetwork.java \
    android/gradle.properties \
	android/src/org/qtproject/qt/android/purchasing/Security.java \
	android/src/org/qtproject/qt/android/purchasing/InAppPurchase.java \
	android/src/org/qtproject/qt/android/purchasing/Base64.java \
	android/src/org/qtproject/qt/android/purchasing/Base64DecoderException.java \
	ios/AppDelegate.swift \
	ios/BLEPeripheralManager.swift

win32: DISTFILES += \
   $$PWD/adb/AdbWinApi.dll \
	$$PWD/adb/AdbWinUsbApi.dll \
	$$PWD/adb/adb.exe \


ios {
    ios_icon.files = $$files($$PWD/icons/ios/*.png)
	 QMAKE_BUNDLE_DATA += ios_icon
}

ios {
    OBJECTIVE_SOURCES += ios/lockscreen.mm \
    ios/ios_eliteariafan.mm \
    ios/ios_app_delegate.mm \
	 fit-sdk/FitDecode.mm \
	 fit-sdk/FitDeveloperField.mm \
	 fit-sdk/FitEncode.mm \
	 fit-sdk/FitField.mm \
	 fit-sdk/FitFieldDefinition.mm \
	 fit-sdk/FitMesg.mm \
         fit-sdk/FitMesgDefinition.mm \
         ios/M3iNS.mm \

    SOURCES += ios/M3iNSQT.cpp

    OBJECTIVE_HEADERS += ios/M3iNS.h

    QMAKE_INFO_PLIST = ios/Info.plist
	 QMAKE_ASSET_CATALOGS = $$PWD/ios/Images.xcassets
	 QMAKE_ASSET_CATALOGS_APP_ICON = "AppIcon"
	 QMAKE_ASSET_CATALOGS_BUILD_PATH = $$PWD/ios/ 

    TARGET = qdomyoszwift
	 QMAKE_TARGET_BUNDLE_PREFIX = org.cagnulein
    DEFINES+=_Nullable_result=_Nullable NS_FORMAT_ARGUMENT\\(A\\)=
}

include($$PWD/purchasing/purchasing.pri)
INCLUDEPATH += purchasing/qmltypes
INCLUDEPATH += purchasing/inapp

WINRT_MANIFEST = AppxManifest.xml

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../fit-sdk/release/ -lfit-sdk
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../fit-sdk/debug/ -lfit-sdk
else:unix: LIBS += -L$$OUT_PWD/../fit-sdk/ -lfit-sdk

INCLUDEPATH += $$PWD/../fit-sdk
DEPENDPATH += $$PWD/../fit-sdk

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../fit-sdk/release/libfit-sdk.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../fit-sdk/debug/libfit-sdk.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../fit-sdk/release/fit-sdk.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../fit-sdk/debug/fit-sdk.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../fit-sdk/libfit-sdk.a

VERSION = 2.16.41
