#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStandardPaths>
#include "qqml.h"

#include "qqmldom.h"
#include "qnetworkscanner.h"
#include "qinstallerconfigure.h"
#include "qinstallerpackage.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    qmlRegisterType<QQMlDom>("InstallerFrontEnd",1,0,"QQmlDom");
    qmlRegisterType<QInstallerConfigure>("InstallerFrontEnd",1,0,"ConfigXml");


    qmlRegisterType<QNetworkScanner>("InstallerFrontEnd",1,0,"QNetworkScanner");

    QString buildDefaultDir = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first();
    engine.rootContext()->setContextProperty("buildDefaultDir",buildDefaultDir);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

