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


#include <QFile>
#include <QList>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QObject>
#include <QDir>
#include <QSettings>


#include "qnetworkscanner.h"

/**********************************************************************
* config.xml
**********************************************************************/
class QInstallerConfigure : public QObject{
    Q_OBJECT

    Q_PROPERTY(QString rootDir READ rootDir WRITE setRootDir NOTIFY rootDirChanged)


    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString version READ version WRITE setVersion NOTIFY versionChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString publisher READ publisher WRITE setPublisher NOTIFY publisherChanged)
    Q_PROPERTY(QString productUrl READ productUrl WRITE setProductUrl NOTIFY productUrlChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QString installerApplicationIcon READ installerApplicationIcon WRITE setInstallerApplicationIcon NOTIFY installerApplicationIconChanged)
    Q_PROPERTY(QString installerWindowIcon READ installerWindowIcon WRITE setInstallerWindowIcon NOTIFY installerWindowIconChanged)
    Q_PROPERTY(QString logo READ logo WRITE setLogo NOTIFY logoChanged)
    Q_PROPERTY(QString watermark READ watermark WRITE setWatermark NOTIFY watermarkChanged)
    Q_PROPERTY(QString banner READ banner WRITE setBanner NOTIFY bannerChanged)
    Q_PROPERTY(QString background READ background WRITE setBackground NOTIFY backgroundChanged)
    Q_PROPERTY(QString wizardStyle READ wizardStyle WRITE setWizardStyle NOTIFY wizardStyleChanged)
    Q_PROPERTY(QString wizardDefaultWidth READ wizardDefaultWidth WRITE setWizardDefaultWidth NOTIFY wizardDefaultWidthChanged)
    Q_PROPERTY(QString wizardDefaultHeight READ wizardDefaultHeight WRITE setWizardDefaultHeight NOTIFY wizardDefaultHeightChanged)
    Q_PROPERTY(QString titleColor READ titleColor WRITE setTitleColor NOTIFY titleColorChanged)
    Q_PROPERTY(QString runProgram READ runProgram WRITE setRunProgram NOTIFY runProgramChanged)
    Q_PROPERTY(QString runProgramArguments READ runProgramArguments WRITE setRunProgramArguments NOTIFY runProgramArgumentsChanged)
    Q_PROPERTY(QString runProgramDescription READ runProgramDescription WRITE setRunProgramDescription NOTIFY runProgramDescriptionChanged)
    Q_PROPERTY(QString startMenuDir READ startMenuDir WRITE setStartMenuDir NOTIFY startMenuDirChanged)
    Q_PROPERTY(QString targetDir READ targetDir WRITE setTargetDir NOTIFY targetDirChanged)
    Q_PROPERTY(QString adminTargetDir READ adminTargetDir WRITE setAdminTargetDir NOTIFY adminTargetDirChanged)
    Q_PROPERTY(QString remoteRepositories READ remoteRepositories WRITE setRemoteRepositories NOTIFY remoteRepositoriesChanged)
    Q_PROPERTY(QString maintenanceToolName READ maintenanceToolName WRITE setMaintenanceToolName NOTIFY maintenanceToolNameChanged)
    Q_PROPERTY(QString maintenanceToolIniFile READ maintenanceToolIniFile WRITE setMaintenanceToolIniFile NOTIFY maintenanceToolIniFileChanged)
    Q_PROPERTY(QString removeTargetDir READ removeTargetDir WRITE setRemoveTargetDir NOTIFY removeTargetDirChanged)
    Q_PROPERTY(QString allowNonAsciiCharacters READ allowNonAsciiCharacters WRITE setAllowNonAsciiCharacters NOTIFY allowNonAsciiCharactersChanged)
    Q_PROPERTY(QString allowSpaceInPath READ allowSpaceInPath WRITE setAllowSpaceInPath NOTIFY allowSpaceInPathChanged)
    Q_PROPERTY(QString dependsOnLocalInstallerBinary READ dependsOnLocalInstallerBinary WRITE setDependsOnLocalInstallerBinary NOTIFY dependsOnLocalInstallerBinaryChanged)
    Q_PROPERTY(QString targetConfigurationFile READ targetConfigurationFile WRITE setTargetConfigurationFile NOTIFY targetConfigurationFileChanged)
    Q_PROPERTY(QString translations READ translations WRITE setTranslations NOTIFY translationsChanged)
    Q_PROPERTY(QString urlQueryString READ urlQueryString WRITE setUrlQueryString NOTIFY urlQueryStringChanged)
    Q_PROPERTY(QString controlScript READ controlScript WRITE setControlScript NOTIFY controlScriptChanged)
    Q_PROPERTY(QString createLocalRepository READ createLocalRepository WRITE setCreateLocalRepository NOTIFY createLocalRepositoryChanged)


public:
    explicit QInstallerConfigure(QObject *parent = 0);
    /*******
 *   Getters
 *******/
    QString rootDir()const;

    QString name()const;
    QString version()const;
    QString title()const;
    QString publisher()const;
    QString productUrl()const;
    QString icon()const;
    QString installerApplicationIcon()const;

    QString installerWindowIcon()const;

    QString logo()const;
    QString watermark()const;
    QString banner()const;
    QString background()const;
    QString wizardStyle()const;
    QString wizardDefaultWidth()const;
    QString wizardDefaultHeight()const;
    QString titleColor()const;
    QString runProgram()const;
    QString runProgramArguments()const;
    QString runProgramDescription()const;
    QString startMenuDir()const;
    QString targetDir()const;
    QString adminTargetDir()const;
    QString remoteRepositories()const;
    QString maintenanceToolName()const;
    QString maintenanceToolIniFile()const;
    QString removeTargetDir()const;
    QString allowNonAsciiCharacters()const;
    QString repositorySettingsPageVisible()const;
    QString allowSpaceInPath()const;
    QString dependsOnLocalInstallerBinary()const;
    QString targetConfigurationFile()const;
    QString translations()const;
    QString urlQueryString()const;
    QString controlScript()const;
    QString createLocalRepository()const;

    /*********
* Setters
*********/
    void setRootDir(const QString &rootDir);


    void setName(const QString &name);
    void setVersion(const QString &version);
    void setTitle(const QString &title);
    void setPublisher(const QString &publisher);
    void setProductUrl(const QString &productUrl);
    void setIcon(const QString &icon);
    void setInstallerApplicationIcon(const QString &installerApplicationIcon);
    void setInstallerWindowIcon(const QString &installerWindowIcon);
    void setLogo(const QString &logo);
    void setWatermark(const QString &watermark);
    void setBanner(const QString &banner);
    void setBackground(const QString &background);
    void setWizardStyle(const QString &wizardStyle);
    void setWizardDefaultWidth(const QString &wizardDefaultWidth);
    void setWizardDefaultHeight(const QString &wizardDefaultHeight);
    void setTitleColor(const QString &titleColor);
    void setRunProgram(const QString &runProgram);
    void setRunProgramArguments(const QString &runProgramArguments);
    void setRunProgramDescription(const QString &runProgramDescription);
    void setStartMenuDir(const QString &startMenuDir);
    void setTargetDir(const QString &targetDir);
    void setAdminTargetDir(const QString &adminTargetDir);
    void setRemoteRepositories(const QString &remoteRepositories);
    void setMaintenanceToolName(const QString &maintenanceToolName);
    void setMaintenanceToolIniFile(const QString &maintenanceToolIniFile);
    void setRemoveTargetDir(const QString &removeTargetDir);
    void setAllowNonAsciiCharacters(const QString &allowNonAsciiCharacters);
    void setRepositorySettingsPageVisible(const QString &repositorySettingsPageVisible);
    void setAllowSpaceInPath(const QString &allowSpaceInPath);
    void setDependsOnLocalInstallerBinary(const QString &dependsOnLocalInstallerBinary);
    void setTargetConfigurationFile(const QString &targetConfigurationFile);
    void setTranslations(const QString &translations);
    void setUrlQueryString(const QString &urlQueryString);
    void setControlScript(const QString &controlScript);
    void setCreateLocalRepository(const QString &createLocalRepository);




signals:
    void rootDirChanged();

    void nameChanged();
    void versionChanged();
    void titleChanged();
    void publisherChanged();
    void productUrlChanged();
    void iconChanged();
    void installerApplicationIconChanged();
    void installerWindowIconChanged();
    void logoChanged();
    void watermarkChanged();
    void bannerChanged();
    void backgroundChanged();
    void wizardStyleChanged();
    void wizardDefaultWidthChanged();
    void wizardDefaultHeightChanged();
    void titleColorChanged();
    void runProgramChanged();
    void runProgramArgumentsChanged();
    void runProgramDescriptionChanged();
    void startMenuDirChanged();
    void targetDirChanged();
    void adminTargetDirChanged();
    void remoteRepositoriesChanged();
    void maintenanceToolNameChanged();
    void maintenanceToolIniFileChanged();
    void removeTargetDirChanged();
    void allowNonAsciiCharactersChanged();
    void repositorySettingsPageVisibleChanged();
    void allowSpaceInPathChanged();
    void dependsOnLocalInstallerBinaryChanged();
    void targetConfigurationFileChanged();
    void translationsChanged();
    void urlQueryStringChanged();
    void controlScriptChanged();
    void createLocalRepositoryChanged();
private:
    QString m_rootDir;

    QString m_name;
    QString m_version;
    QString m_title;
    QString m_publisher;
    QString m_productUrl;
    QString m_icon;
    QString m_installerApplicationIcon;
    QString m_installerWindowIcon;
    QString m_logo;
    QString m_watermark;
    QString m_banner;
    QString m_background;
    QString m_wizardStyle;
    QString m_wizardDefaultWidth;
    QString m_wizardDefaultHeight;
    QString m_titleColor;
    QString m_runProgram;
    QString m_runProgramArguments;
    QString m_runProgramDescription;
    QString m_startMenuDir;
    QString m_targetDir;
    QString m_adminTargetDir;
    QString m_remoteRepositories;
    QString m_maintenanceToolName;
    QString m_maintenanceToolIniFile;
    QString m_removeTargetDir;
    QString m_allowNonAsciiCharacters;
    QString m_repositorySettingsPageVisible;
    QString m_allowSpaceInPath;
    QString m_dependsOnLocalInstallerBinary;
    QString m_targetConfigurationFile;
    QString m_translations;
    QString m_urlQueryString;
    QString m_controlScript;
    QString m_createLocalRepository;

};



/**************************************************************************
 * Package.XML
 *************************************************************************/
class QInstallerPackage : public QObject{

    Q_OBJECT
    Q_PROPERTY(QString displayName READ displayName WRITE setDisplayName NOTIFY displayNameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString version READ version WRITE setVersion NOTIFY versionChanged)
    Q_PROPERTY(QString releaseDate READ releaseDate WRITE setReleaseDate NOTIFY releaseDateChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString dependencies READ dependencies WRITE setDependencies NOTIFY dependenciesChanged)
    Q_PROPERTY(QString autoDependOn READ autoDependOn WRITE setAutoDependOn NOTIFY autoDependOnChanged)
    Q_PROPERTY(QString packageVirtual READ packageVirtual WRITE setPackageVirtual NOTIFY packageVirtualChanged)
    Q_PROPERTY(QString sortingPriority READ sortingPriority WRITE setSortingPriority NOTIFY sortingPriorityChanged)
    Q_PROPERTY(QString licenses READ licenses WRITE setLicenses NOTIFY licensesChanged)
    Q_PROPERTY(QString script READ script WRITE setScript NOTIFY scriptChanged)
    Q_PROPERTY(QString userInterfaces READ userInterfaces WRITE setUserInterfaces NOTIFY userInterfacesChanged)
    Q_PROPERTY(QString translations READ translations WRITE setTranslations NOTIFY translationsChanged)
    Q_PROPERTY(QString updateText READ updateText WRITE setUpdateText NOTIFY updateTextChanged)
    Q_PROPERTY(QString packageDefault READ packageDefault WRITE setPackageDefault NOTIFY packageDefaultChanged)
    Q_PROPERTY(QString essential READ essential WRITE setEssential NOTIFY essentialChanged)
    Q_PROPERTY(QString forcedInstallation READ forcedInstallation WRITE setForcedInstallation NOTIFY forcedInstallationChanged)
    Q_PROPERTY(QString replaces READ replaces WRITE setReplaces NOTIFY replacesChanged)
    Q_PROPERTY(QString downloadableArchives READ downloadableArchives WRITE setDownloadableArchives NOTIFY downloadableArchivesChanged)
    Q_PROPERTY(QString requiresAdminRights READ requiresAdminRights WRITE setRequiresAdminRights NOTIFY requiresAdminRightsChanged)

    explicit QInstallerPackage(QObject *parent = 0);

    /*
     * Getters
     */

    QString displayName()const;
    QString description()const;
    QString version()const;
    QString releaseDate()const;
    QString name()const;
    QString dependencies()const;
    QString autoDependOn()const;
    QString packageVirtual()const;
    QString sortingPriority()const;
    QString licenses()const;
    QString script()const;
    QString userInterfaces()const;
    QString translations()const;
    QString updateText()const;
    QString packageDefault()const;
    QString essential()const;
    QString forcedInstallation()const;
    QString replaces()const;
    QString downloadableArchives()const;
    QString requiresAdminRights()const;



    /*
     * Setters
     */
    void setDisplayName(const QString &displayName);
    void setDescription(const QString &description);
    void setVersion(const QString &version);
    void setReleaseDate(const QString &releaseDate);
    void setName(const QString &name);
    void setDependencies(const QString &dependencies);
    void setAutoDependOn(const QString &autoDependOn);
    void setPackageVirtual(const QString &packageVirtual);
    void setSortingPriority(const QString &sortingPriority);
    void setLicenses(const QString &licenses);
    void setScript(const QString &script);
    void setUserInterfaces(const QString &userInterfaces);
    void setTranslations(const QString &translations);
    void setUpdateText(const QString &updateText);
    void setPackageDefault(const QString &packageDefault);
    void setEssential(const QString &essential);
    void setForcedInstallation(const QString &forcedInstallation);
    void setReplaces(const QString &replaces);
    void setDownloadableArchives(const QString &downloadableArchives);
    void setRequiresAdminRights(const QString &requiresAdminRights);


signals:
    void displayNameChanged();
    void descriptionChanged();
    void versionChanged();
    void releaseDateChanged();
    void nameChanged();
    void dependenciesChanged();
    void autoDependOnChanged();
    void packageVirtualChanged();
    void sortingPriorityChanged();
    void licensesChanged();
    void scriptChanged();
    void userInterfacesChanged();
    void translationsChanged();
    void updateTextChanged();
    void packageDefaultChanged();
    void essentialChanged();
    void forcedInstallationChanged();
    void replacesChanged();
    void downloadableArchivesChanged();
    void requiresAdminRightsChanged();
private:

    QString m_displayName;
    QString m_description;
    QString m_version;
    QString m_releaseDate;
    QString m_name;
    QString m_dependencies;
    QString m_autoDependOn;
    QString m_packageVirtual;
    QString m_sortingPriority;
    QString m_licenses;
    QString m_script;
    QString m_userInterfaces;
    QString m_translations;
    QString m_updateText;
    QString m_packageDefault;
    QString m_essential;
    QString m_forcedInstallation;
    QString m_replaces;
    QString m_downloadableArchives;
    QString m_requiresAdminRights;

};





/*******************************************************************************
 *  QDom and other functions that are needed to make each of the xml files and
 *  run all the qprocess things like binary creator and make static qt
 * ****************************************************************************/
class QQMlDom : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString binaryLoaction READ binaryLoaction WRITE setBinaryCreatorLocation NOTIFY binaryLoactionChanged)
    Q_PROPERTY(bool staticBuild READ staticBuild WRITE setStaticBuild NOTIFY staticBuildChanged)


public:
    explicit QQMlDom(QObject *parent = 0);


    bool staticBuild();
    void setStaticBuild(const bool &staticBuild);


    Q_INVOKABLE void downloadPrebuilt()const;
    QStringList getPrebuiltOptions();


    QString binaryLoaction()const;
    void setBinaryCreatorLocation(const QString &binaryLoaction);
    Q_INVOKABLE bool hasTheBinaryPath() const;

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


    // Q_INVOKABLE void writePackagePage();

    // These are single removers and will break on multiple children
    void addependTextById(QDomDocument nDocument ,QString element,QString text);
    void addependAttributeById(QDomElement nDocument ,QString element,QString attribute);
    void createNewNode(QDomDocument nDocument , QDomElement nElement, QString parent, QString nodeName);


    void removeDefaultNode(QDomElement nDocument ,QString element);
    void removeNodeById( QDomElement nDocument , QString element);

signals:
    void error(QString);
    void binaryLoactionChanged();
    void staticBuildChanged();


protected slots:
    void handleError(const QString err);


private:
    QDomDocument m_document;
    QSettings m_binaryLoc;
    QString m_binaryLocation;
    bool m_staticBuild;
};

#endif // QQMLDOM_H
