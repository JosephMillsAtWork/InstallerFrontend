#ifndef QQMLDOM_H
#define QQMLDOM_H

#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomNode>
#include <QtXml/QtXml>
#include <QtWebKit/QWebElement>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include <QLocale>

#include <QFile>
#include <QList>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QObject>
#include <QDir>
#include <QSettings>


#include "qqmlnetwork.h"


/*******************************************************************************
 *  QDom and other functions that are needed to make each of the xml files and
 *  run all the qprocess things like binary creator and make static qt
 * ****************************************************************************/
class QQMlDom : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString binaryLoaction READ binaryLoaction WRITE setBinaryCreatorLocation NOTIFY binaryLoactionChanged)
    Q_PROPERTY(bool staticBuild READ staticBuild WRITE setStaticBuild NOTIFY staticBuildChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorStringChanged)
    Q_PROPERTY(QStringList getPrebuiltVersions READ getPrebuiltVersions)
    Q_PROPERTY(QString getCorrectPreBuilt READ getCorrectPreBuilt)


public:
    explicit QQMlDom(QObject *parent = 0);


    QString errorString();

    bool staticBuild();
    void setStaticBuild(const bool &staticBuild);


    QString getCorrectPreBuilt();
    Q_INVOKABLE void setCorrectPreBuilt(const QString version);


    QStringList getPrebuiltVersions();
    void setPrebuiltVersions();

    QString binaryLoaction()const;
    Q_INVOKABLE void setBinaryCreatorLocation(const QString &binaryLoaction);
    Q_INVOKABLE bool hasTheBinaryPath() const;
//    Q_INVOKABLE void setBinaryPath();


    Q_INVOKABLE void writeConfigPage(const QString path);
    Q_INVOKABLE void writePackagePage(const QString path);
    Q_INVOKABLE void checkConfigManditory(const QString &element, QString text);

    Q_INVOKABLE bool dirExists(const QString dir);
    Q_INVOKABLE void copyBinary();
    Q_INVOKABLE void mkDefaultDirs(const QString rootDir,const QString projectName,const QString appName);


    Q_INVOKABLE bool createSubPackageComponent();

    QStringList getDefaultConfigXml();
    QStringList getDefaultPackageXml();
    void makeProFile(const QString rootDir,const QString projectName);
    void makeConfigFile(const QString rootDir,const QString projectName );
    void makePackageFile(const QString rootDir,const QString projectName );
    void makeREADMEFile(const QString rootDir,const QString projectName );
    void makeQSFile(const QString rootDir,const QString projectName );
    void makeLicenseFile(const QString rootDir,const QString projectName);

    // These are single removers and will break on multiple children
   Q_INVOKABLE void addependTextById(QDomDocument nDocument ,QString element,QString text);
   Q_INVOKABLE void addependAttributeById(QDomElement nDocument ,QString element,QString attribute);
   Q_INVOKABLE void createNewNode(QDomDocument nDocument , QDomElement nElement, QString parent, QString nodeName);


   Q_INVOKABLE void removeDefaultNode(QDomElement nDocument ,QString element);
   Q_INVOKABLE void removeNodeById( QDomElement nDocument , QString element);

    Q_INVOKABLE void gCC();
signals:
    void error(QString);
    void binaryLoactionChanged();
    void staticBuildChanged();
    void errorStringChanged();

protected slots:
    void handleError(const QString err);


private:
    QDomDocument m_document;
    QSettings m_binaryLoc;
    QString m_binaryLocation;
    bool m_staticBuild;
    QString m_errorString;
    QStringList m_preBuildVersions;
    QString m_correctPrebuiltUrl;
};

#endif // QQMLDOM_H
