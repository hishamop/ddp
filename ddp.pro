TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

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

DISTFILES += \
    input.in
