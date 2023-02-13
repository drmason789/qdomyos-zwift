QT += bluetooth xml

unix:android: QT += androidextras gui-private

android: include(android_openssl/openssl.pri)

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/src/android

ANDROID_ABIS = armeabi-v7a arm64-v8a x86 x86_64

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS IO_UNDER_QT SMTP_BUILD


include(version.pri)
