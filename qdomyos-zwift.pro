TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS = \
    src/qdomyos-zwift-lib.pro    \
    src/qdomyos-zwift.pro \
    tst/qdomyos-zwift-tests.pro

tst.depends = src/qdomyos-zwift-lib.pro

 
