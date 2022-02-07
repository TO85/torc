#QT -= gui
QT *= widgets

TEMPLATE = lib
DEFINES += OCIO_LIBRARY

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../useBase.pri)

SOURCES += \
    DirectoryTreeWidget.cpp \
    DirectoryTreeWidgetItem.cpp \
    FileInfoTableWidget.cpp \
    FileInfoTableWidgetItem.cpp \
    FileSystemObject.cpp \
    FileSystemTree.cpp \
    ocIO.cpp

HEADERS += \
    ../../include/DirectoryTreeEntry \
    ../../include/DirectoryTreeWidget \
    ../../include/DirectoryTreeWidgetItem \
    ../../include/FileInfoTableWidget \
    ../../include/FileInfoTableWidgetItem \
    ../../include/FileSystemObject \
    ../../include/FileSystemTree \
    DirectoryTreeWidget.h \
    DirectoryTreeWidgetItem.h \
    FileInfoTableWidget.h \
    FileInfoTableWidgetItem.h \
    FileSystemObject.h \
    FileSystemTree.h \
    ocIO_global.h \
    ocIO.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

QT += widgets
