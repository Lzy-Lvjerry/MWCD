# 1. ≈‰÷√mathglª∑æ≥


DEFINES += MATHGL_DLL

INCLUDEPATH += $$PWD/include
CONFIG += static
LIBS += -L$$PWD/lib/ -lmgl-qt5 -lmgl

HEADERS += \
    $$PWD/src/QDrawWindow.h \
    $$PWD/src/QDWData.h \
    $$PWD/src/PlotGraph.h \
    $$PWD/src/GraphData.h \
    $$PWD/src/TorusGraph.h

SOURCES += \
    $$PWD/src/QDrawWindow.cpp \
    $$PWD/src/QDWData.cpp \
    $$PWD/src/PlotGraph.cpp \
    $$PWD/src/GraphData.cpp \
    $$PWD/src/TorusGraph.cpp
