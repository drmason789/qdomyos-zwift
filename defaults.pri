QT += bluetooth xml

unix:android: QT += androidextras gui-private

android: include(android_openssl/openssl.pri)

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/src/android

ANDROID_ABIS = armeabi-v7a arm64-v8a x86 x86_64

include(version.pri)
