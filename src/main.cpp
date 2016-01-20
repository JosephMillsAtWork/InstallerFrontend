#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStandardPaths>
#include "qqml.h"

#include "qqmldom.h"
#include "qqmlnetwork.h"
#include "qinstallerconfigure.h"
#include "qinstallerpackage.h"
#include "qqmlfilepermissions.h"
#include "qqmlprocess.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    qmlRegisterType<QQMlDom>("InstallerFrontEnd",1,0,"QQmlDom");
    qmlRegisterType<QInstallerConfigure>("InstallerFrontEnd",1,0,"ConfigXml");
    qmlRegisterType<QQmlNetwork>("InstallerFrontEnd",1,0,"QQmlNetwork");
    qmlRegisterType<QQmlFilePermissions>("InstallerFrontEnd",1,0,"QQmlFilePermissions");
    qmlRegisterType<QQmlProcess>("InstallerFrontEnd",1,0,"QQmlProcess");


    QString downloadDir = QStandardPaths::standardLocations(QStandardPaths::DownloadLocation).first();
    QString buildDefaultDir = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first();
    QString homeDir = QStandardPaths::standardLocations(QStandardPaths::HomeLocation).first();

    engine.rootContext()->setContextProperty("buildDefaultDir",buildDefaultDir);
    engine.rootContext()->setContextProperty("downloadDir",downloadDir);
    engine.rootContext()->setContextProperty("homeDir",homeDir);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

