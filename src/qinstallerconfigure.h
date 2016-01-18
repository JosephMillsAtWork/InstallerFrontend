#ifndef QINSTALLERCONFIGURE_H
#define QINSTALLERCONFIGURE_H

#include <QObject>

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

#endif // QINSTALLERCONFIGURE_H
