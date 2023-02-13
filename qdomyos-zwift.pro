TEMPLATE = subdirs

SUBDIRS = lib
lib.file = lib/qdomyos-zwift-lib.pro


SUBDIRS += src
src.file = src/qdomyos-zwift.pro
src.depends = lib

!android: {
    SUBDIRS += tst
    tst.file = tst/qdomyos-zwift-tests.pro
    tst.depends = lib
}
