TEMPLATE = app

QT += qml \
      quick \
      xml \
      core \
      network
#      positioning

CONFIG += c++11

SOURCES += src/main.cpp \
    src/qqmldom.cpp \
    src/qinstallerpackage.cpp \
    src/qinstallerconfigure.cpp \
    src/qqmlnetwork.cpp \
    src/qqmlfilepermissions.cpp \
    src/qqmlprocess.cpp

RESOURCES += qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/qqmldom.h \
    src/qinstallerpackage.h \
    src/qinstallerconfigure.h \
    src/qqmlnetwork.h \
    src/qqmlfilepermissions.h \
    src/qqmlprocess.h

