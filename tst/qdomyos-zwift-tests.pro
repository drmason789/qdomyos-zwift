include(qdomyos-zwift-tests.pri)

TEMPLATE = subdirs

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

INCLUDEPATH += src/qmdnsengine/src/include

SUBDIRS = Devices

