TEMPLATE = subdirs

SUBDIRS = lib src

src.file = src/qdomyos-zwift.pro
lib.file = lib/qdomyos-zwift-lib.pro
src.depends = lib


!android: {
    SUBDIRS += tst

    tst.file = tst/qdomyos-zwift-tests.pro
    tst.depends = lib
}
