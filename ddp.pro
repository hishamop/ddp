TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -O3 -pipe -DNDEBUG    -DIPOPT_BUILD
QMAKE_CXXFLAGS += -I /home/shamil/lib/ipopt/Lib/include/coin -w


INCLUDEPATH += $$PWD/home/shamil/lib/ipopt/Lib/include/coin

SOURCES += main.cpp \
    feval.cpp \
    quad.cpp \
    solve.cpp \
    nodeset.cpp \
    node.cpp \
    nlp.cpp \
    material.cpp \
    load.cpp \
    ipopt_solve.cpp \
    elset.cpp \
    element.cpp \
    cps4.cpp \
    cmodel.cpp \
    cfileio.cpp \
    boundary.cpp


HEADERS += \
    feval.h \
    quad.h \
    solve.h \
    nodeset.h \
    node.h \
    nlp.h \
    material.h \
    load.h \
    ipopt_solve.h \
    elset.h \
    element_types.h \
    element.h \
    cps4.h \
    cmodel.h \
    cfileio.h \
    boundary.h \
    auxil.h \
    enums.h \
    common.h \
    options.h

DISTFILES += \
    input.in \
    LICENSE \
    README.md \
    Doxyfile
