QT += gui

TEMPLATE = lib
DEFINES += OCCOLOR_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../useBase.pri)
include(../useGui.pri)

SOURCES += \
    Color.cpp \
    CompoundColor.cpp \
    RgbColorTable.cpp \
    ocColor.cpp

HEADERS += \
    ../../include/Color \
    ../../include/CompoundColor \
    Color.h \
    CompoundColor.h \
    RgbColorTable.h \
    ocColor_global.h \
    ocColor.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
