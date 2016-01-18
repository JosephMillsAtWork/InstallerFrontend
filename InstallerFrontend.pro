TEMPLATE = app

QT += qml quick xml core
CONFIG += c++11

SOURCES += src/main.cpp \
    src/qqmldom.cpp \
    src/qnetworkscanner.cpp

RESOURCES += qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/qqmldom.h \
    src/qnetworkscanner.h

