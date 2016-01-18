#include "qinstallerconfigure.h"
QInstallerConfigure::QInstallerConfigure(QObject *parent):
    QObject(parent),
     m_name("Application"),
     m_version("1.0.0"),
     m_title("Title Shown in Installer"),
     m_publisher("My Name"),
     m_productUrl("http://aplcae.com"),
     m_icon(),
     m_installerApplicationIcon(),
     m_installerWindowIcon(),
     m_logo(),
     m_watermark(),
     m_banner(),
     m_background(),
     m_wizardStyle("Modern"),
     m_wizardDefaultWidth(),
     m_wizardDefaultHeight(),
     m_titleColor("black"),
     m_runProgram(),
     m_runProgramArguments(),
     m_runProgramDescription(),
     m_startMenuDir("Qt"),
     m_targetDir("@HomeDir@/Application"),
     m_adminTargetDir(),
     m_remoteRepositories(),
     m_maintenanceToolName(),
     m_maintenanceToolIniFile(),
     m_removeTargetDir("@HomeDir@/Applciation"),
     m_allowNonAsciiCharacters("False"),
     m_repositorySettingsPageVisible("False"),
     m_allowSpaceInPath("False"),
     m_dependsOnLocalInstallerBinary("False"),
     m_targetConfigurationFile(),
     m_translations(),
     m_urlQueryString(),
     m_controlScript(),
     m_createLocalRepository()
{

}

QString QInstallerConfigure::rootDir() const
{
    return m_rootDir;
}

QString QInstallerConfigure::name() const
{
    return m_name;
}

QString QInstallerConfigure::version() const
{
    return m_version;
}

QString QInstallerConfigure::title() const
{
    return m_title;
}

QString QInstallerConfigure::publisher() const
{
    return m_publisher;
}

QString QInstallerConfigure::productUrl() const
{
    return m_productUrl;
}

QString QInstallerConfigure::icon() const
{
    return m_icon;
}

QString QInstallerConfigure::installerApplicationIcon() const
{
    return m_installerApplicationIcon;
}

QString QInstallerConfigure::installerWindowIcon() const
{
    return m_installerWindowIcon;
}

QString QInstallerConfigure::logo() const
{
    return m_logo;
}

QString QInstallerConfigure::watermark() const
{
    return m_watermark;
}

QString QInstallerConfigure::banner() const
{
    return m_banner;
}

QString QInstallerConfigure::background() const
{
    return m_banner;
}

QString QInstallerConfigure::wizardStyle() const
{
    return m_wizardStyle;
}

QString QInstallerConfigure::wizardDefaultWidth() const
{
    return m_wizardDefaultWidth;
}

QString QInstallerConfigure::wizardDefaultHeight() const
{
    return m_wizardDefaultHeight;
}

QString QInstallerConfigure::titleColor() const
{
    return m_title;
}

QString QInstallerConfigure::runProgram() const
{
    return m_runProgram;
}

QString QInstallerConfigure::runProgramArguments() const
{
    return m_runProgramArguments;
}

QString QInstallerConfigure::runProgramDescription() const
{
    return m_runProgramDescription;
}

QString QInstallerConfigure::startMenuDir() const
{
    return m_startMenuDir;
}

QString QInstallerConfigure::targetDir() const
{
    return m_targetDir;
}

QString QInstallerConfigure::adminTargetDir() const
{
    return m_adminTargetDir;
}

QString QInstallerConfigure::remoteRepositories() const
{
    return m_remoteRepositories;
}

QString QInstallerConfigure::maintenanceToolName() const
{
    return m_maintenanceToolName;
}

QString QInstallerConfigure::maintenanceToolIniFile() const
{
    return m_maintenanceToolIniFile;
}

QString QInstallerConfigure::removeTargetDir() const
{
    return m_removeTargetDir;
}

QString QInstallerConfigure::allowNonAsciiCharacters() const
{
    return m_allowNonAsciiCharacters;
}

QString QInstallerConfigure::repositorySettingsPageVisible() const
{
    return m_repositorySettingsPageVisible;
}

QString QInstallerConfigure::allowSpaceInPath() const
{
    return m_allowSpaceInPath;
}

QString QInstallerConfigure::dependsOnLocalInstallerBinary() const
{
    return m_dependsOnLocalInstallerBinary;
}

QString QInstallerConfigure::targetConfigurationFile() const
{
    return m_targetConfigurationFile;
}

QString QInstallerConfigure::translations() const
{
    return m_translations;
}

QString QInstallerConfigure::urlQueryString() const
{
    return m_urlQueryString;
}

QString QInstallerConfigure::controlScript() const
{
    return m_controlScript;
}

QString QInstallerConfigure::createLocalRepository() const
{
    return m_createLocalRepository;
}

void QInstallerConfigure::setRootDir(const QString &rootDir)
{
    if(m_rootDir == rootDir)
        return;
    m_rootDir = rootDir;
    emit rootDirChanged();
}



/**************************************
 *
 *      SETTERS
 *
 ************************************/
void QInstallerConfigure::setName(const QString &name)
{
    if(m_name == name )
        return;
    m_name = name;
    emit nameChanged();
}

void QInstallerConfigure::setVersion(const QString &version)
{
    if(m_version == version)
        return;
    m_version = version;
    emit versionChanged();
}

void QInstallerConfigure::setTitle(const QString &title)
{
    if(m_title == title)
        return;
    m_title = title;
    emit titleChanged();
}

void QInstallerConfigure::setPublisher(const QString &publisher)
{
    if(m_publisher == publisher)
        return;
    m_publisher =publisher ;
    emit publisherChanged() ;
}

void QInstallerConfigure::setProductUrl(const QString &productUrl)
{
    if(m_productUrl == productUrl )
        return;
    m_productUrl = productUrl;
    emit productUrlChanged();
}

void QInstallerConfigure::setIcon(const QString &icon)
{
    if(m_icon == icon)
        return;
    m_icon = icon;
    emit iconChanged();
}

void QInstallerConfigure::setInstallerApplicationIcon(const QString &installerApplicationIcon)
{
    if(m_installerApplicationIcon == installerApplicationIcon )
        return;
    m_installerApplicationIcon = installerApplicationIcon;
    emit installerApplicationIconChanged();
}

void QInstallerConfigure::setInstallerWindowIcon(const QString &installerWindowIcon)
{
    if(m_installerWindowIcon == installerWindowIcon)
        return;
    m_installerWindowIcon = installerWindowIcon;
    emit installerWindowIconChanged();

}

void QInstallerConfigure::setLogo(const QString &logo)
{
    if(m_logo == logo)
        return;
    m_logo = logo;
    emit logoChanged();
}

void QInstallerConfigure::setWatermark(const QString &watermark)
{
    if(m_watermark ==watermark )
        return;
    m_watermark = watermark;
    emit watermarkChanged();
}

void QInstallerConfigure::setBanner(const QString &banner)
{
    if(m_banner == banner)
        return;
    m_banner = banner;
    emit bannerChanged();
}

void QInstallerConfigure::setBackground(const QString &background)
{
    if(m_background == background )
        return;
    m_background = background;
    emit backgroundChanged();
}

void QInstallerConfigure::setWizardStyle(const QString &wizardStyle)
{
    if(m_wizardStyle == wizardStyle )
        return;
    m_wizardStyle = wizardStyle;
    emit wizardStyleChanged();
}

void QInstallerConfigure::setWizardDefaultWidth(const QString &wizardDefaultWidth)
{
    if(m_wizardDefaultWidth == wizardDefaultWidth)
        return;
    m_wizardDefaultWidth = wizardDefaultWidth;
    emit wizardDefaultWidthChanged();
}

void QInstallerConfigure::setWizardDefaultHeight(const QString &wizardDefaultHeight)
{
    if(m_wizardDefaultHeight ==  wizardDefaultHeight)
        return;
    m_wizardDefaultHeight = wizardDefaultHeight;
    emit wizardDefaultHeightChanged();
}

void QInstallerConfigure::setTitleColor(const QString &titleColor)
{
    if(m_titleColor == titleColor)
        return;
    m_titleColor = titleColor;
    emit titleColorChanged();
}

void QInstallerConfigure::setRunProgram(const QString &runProgram)
{
    if(m_runProgram == runProgram )
        return;
    m_runProgram = runProgram;
    emit runProgramChanged();
}

void QInstallerConfigure::setRunProgramArguments(const QString &runProgramArguments)
{
    if(m_runProgramArguments == runProgramArguments )
        return;
    m_runProgramArguments = runProgramArguments;
    emit runProgramArgumentsChanged();
}

void QInstallerConfigure::setRunProgramDescription(const QString &runProgramDescription)
{
    if(m_runProgramDescription == runProgramDescription)
        return;
    m_runProgramDescription = runProgramDescription;
    emit runProgramDescriptionChanged();
}

void QInstallerConfigure::setStartMenuDir(const QString &startMenuDir)
{
    if(m_startMenuDir == startMenuDir)
        return;
    m_startMenuDir = startMenuDir;
    emit startMenuDirChanged();
}

void QInstallerConfigure::setTargetDir(const QString &targetDir)
{
    if(m_targetDir == targetDir)
        return;
    m_targetDir = targetDir ;
    emit targetDirChanged();
}

void QInstallerConfigure::setAdminTargetDir(const QString &adminTargetDir)
{
    if(m_adminTargetDir == adminTargetDir)
        return;
    m_adminTargetDir = adminTargetDir;
    emit adminTargetDirChanged();
}

void QInstallerConfigure::setRemoteRepositories(const QString &remoteRepositories)
{
    if(m_remoteRepositories == remoteRepositories )
        return;
    m_remoteRepositories = remoteRepositories ;
    emit remoteRepositoriesChanged();
}

void QInstallerConfigure::setMaintenanceToolName(const QString &maintenanceToolName)
{
    if(m_maintenanceToolName == maintenanceToolName )
        return;
    m_maintenanceToolName = maintenanceToolName;
    emit maintenanceToolNameChanged();
}

void QInstallerConfigure::setMaintenanceToolIniFile(const QString &maintenanceToolIniFile)
{
    if(m_maintenanceToolIniFile == maintenanceToolIniFile )
        return;
    m_maintenanceToolIniFile = maintenanceToolIniFile ;
    emit maintenanceToolIniFileChanged();
}

void QInstallerConfigure::setRemoveTargetDir(const QString &removeTargetDir)
{
    if(m_removeTargetDir == removeTargetDir)
        return;
    m_removeTargetDir = removeTargetDir;
    emit removeTargetDirChanged();
}

void QInstallerConfigure::setAllowNonAsciiCharacters(const QString &allowNonAsciiCharacters)
{
    if(m_allowNonAsciiCharacters == allowNonAsciiCharacters)
        return;
    m_allowNonAsciiCharacters = allowNonAsciiCharacters;
    emit allowNonAsciiCharactersChanged();
}

void QInstallerConfigure::setRepositorySettingsPageVisible(const QString &repositorySettingsPageVisible)
{
    if(m_repositorySettingsPageVisible == repositorySettingsPageVisible)
        return;
    m_repositorySettingsPageVisible = repositorySettingsPageVisible;
    emit repositorySettingsPageVisibleChanged();
}

void QInstallerConfigure::setAllowSpaceInPath(const QString &allowSpaceInPath)
{
    if(m_allowSpaceInPath == allowSpaceInPath)
        return;
    m_allowSpaceInPath = allowSpaceInPath;
    emit allowSpaceInPathChanged();
}

void QInstallerConfigure::setDependsOnLocalInstallerBinary(const QString &dependsOnLocalInstallerBinary)
{
    if(m_dependsOnLocalInstallerBinary == dependsOnLocalInstallerBinary)
        return;
    m_dependsOnLocalInstallerBinary = dependsOnLocalInstallerBinary;
    emit dependsOnLocalInstallerBinaryChanged();
}

void QInstallerConfigure::setTargetConfigurationFile(const QString &targetConfigurationFile)
{
    if(m_targetConfigurationFile == targetConfigurationFile)
        return;
    m_targetConfigurationFile = targetConfigurationFile;
    emit targetConfigurationFileChanged();
}

void QInstallerConfigure::setTranslations(const QString &translations)
{
    if(m_translations == translations)
        return;
    m_translations = translations ;
    emit translationsChanged();
}

void QInstallerConfigure::setUrlQueryString(const QString &urlQueryString)
{
    if(m_urlQueryString == urlQueryString)
        return;
    m_urlQueryString = urlQueryString;
    emit urlQueryStringChanged();
}

void QInstallerConfigure::setControlScript(const QString &controlScript)
{
    if(m_controlScript == controlScript)
        return;
    m_controlScript = controlScript;
    emit controlScriptChanged();
}

void QInstallerConfigure::setCreateLocalRepository(const QString &createLocalRepository)
{
    if(m_createLocalRepository == createLocalRepository)
        return;
    m_createLocalRepository = createLocalRepository;
    emit createLocalRepositoryChanged();
}

