#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "qqml.h"

#include "qqmldom.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    qmlRegisterType<QQMlDom>("InstallerFrontEnd",1,0,"QQmlDom");
    qmlRegisterType<QInstallerConfigure>("InstallerFrontEnd",1,0,"ConfigXml");


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

