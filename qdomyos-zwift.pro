TEMPLATE = subdirs
CONFIG+=ordered


SUBDIRS = \
    src/qdomyos-zwift.pro \
    lib/qdomyos-zwift-lib.pro \
    tst/qdomyos-zwift-tests.pro
    
tst.depends=lib
 

