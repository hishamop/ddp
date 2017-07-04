TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -O3 -pipe -DNDEBUG    -DIPOPT_BUILD
QMAKE_CXXFLAGS += -I /home/hishamop/Ipopt/CoinIpopt/_build/include/coin

LIBS += -L$$PWD/../../Ipopt/CoinIpopt/_build/lib/ -lcoinasl -lcoinblas -lcoinlapack -lcoinmetis -lcoinmumps
LIBS += -L$$PWD/../../Ipopt/CoinIpopt/_build/lib/ -lipopt -lipoptamplinterface

INCLUDEPATH += $$PWD/../../CoinIpopt/_build/include
DEPENDPATH += $$PWD/../../CoinIpopt/_build/include

SOURCES += main.cpp \
    boundary_cps4.cpp \
    boundary.cpp \
    cfileio.cpp \
    cmodel.cpp \
    cps4.cpp \
    dof_handler.cpp \
    element.cpp \
    elset.cpp \
    load.cpp \
    nlp.cpp \
    node.cpp \
    nodeset.cpp \
    ipopt_solve.cpp \
    solve.cpp

HEADERS += \
    auxil.h \
    boundary_cps4.h \
    boundary.h \
    cfileio.h \
    cps4.h \
    cmodel.h \
    dof_handler.h \
    element_types.h \
    element.h \
    elset.h \
    load.h \
    node.h \
    nodeset.h \
    nlp.h \
    ipopt_solve.h \
    solve.h

DISTFILES += \
    input.in
