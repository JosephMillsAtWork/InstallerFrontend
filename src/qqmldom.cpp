#include "qqmldom.h"
/**********************************************************************
* config.xml
**********************************************************************/
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




/**************************************************************************
 * Package.XML
 *************************************************************************/
QInstallerPackage::QInstallerPackage(QObject *parent):
    QObject(parent),
    m_displayName(),
    m_description(),
    m_version(),
    m_releaseDate(),
    m_name(),
    m_dependencies(),
    m_autoDependOn(),
    m_packageVirtual(),
    m_sortingPriority(),
    m_licenses(),
    m_script(),
    m_userInterfaces(),
    m_translations(),
    m_updateText(),
    m_packageDefault(),
    m_essential(),
    m_forcedInstallation(),
    m_replaces(),
    m_downloadableArchives(),
    m_requiresAdminRights()
{

}

/*
 * Getters
 */

QString QInstallerPackage::displayName() const
{
    return m_displayName;
}

QString QInstallerPackage::description() const
{
    return m_description;
}

QString QInstallerPackage::version() const
{
    return m_version;
}

QString QInstallerPackage::releaseDate() const
{
    return m_releaseDate;
}

QString QInstallerPackage::name() const
{
    return m_name;
}

QString QInstallerPackage::dependencies() const
{
    return m_dependencies;
}

QString QInstallerPackage::autoDependOn() const
{
    return m_autoDependOn;
}

QString QInstallerPackage::packageVirtual() const
{
    return m_packageVirtual;
}

QString QInstallerPackage::sortingPriority() const
{
    return m_sortingPriority;
}

QString QInstallerPackage::licenses() const
{
    return m_licenses;
}

QString QInstallerPackage::script() const
{
    return m_script;
}

QString QInstallerPackage::userInterfaces() const
{
    return m_userInterfaces;
}

QString QInstallerPackage::translations() const
{
    return m_translations;
}

QString QInstallerPackage::updateText() const
{
    return m_updateText;
}

QString QInstallerPackage::packageDefault() const
{
    return m_packageDefault;
}

QString QInstallerPackage::essential() const
{
    return m_essential;
}

QString QInstallerPackage::forcedInstallation() const
{
    return m_forcedInstallation;
}

QString QInstallerPackage::replaces() const
{
    return m_replaces;
}

QString QInstallerPackage::downloadableArchives() const
{
    return m_downloadableArchives;
}

QString QInstallerPackage::requiresAdminRights() const
{
    return m_requiresAdminRights;
}


/*
 * Setters
 */

void QInstallerPackage::setDisplayName(const QString &displayName)
{
    if(m_displayName == displayName)
        return;
    m_displayName = displayName ;
    emit displayNameChanged();
}

void QInstallerPackage::setDescription(const QString &description)
{
    if(m_description == description)
        return;
    m_description = description;
    emit  descriptionChanged();
}

void QInstallerPackage::setVersion(const QString &version)
{
    if(m_version == version)
        return;
    m_version = version;
    emit versionChanged(); ;
}

void QInstallerPackage::setReleaseDate(const QString &releaseDate)
{
    if(m_releaseDate == releaseDate)
        return;
    m_releaseDate = releaseDate;
    emit releaseDateChanged(); ;
}

void QInstallerPackage::setName(const QString &name)
{
    if(m_name == name)
        return;
    m_name = name;
    emit nameChanged(); ;
}

void QInstallerPackage::setDependencies(const QString &dependencies)
{
    if(m_dependencies == dependencies)
        return;
    m_dependencies = dependencies;
    emit dependenciesChanged(); ;
}

void QInstallerPackage::setAutoDependOn(const QString &autoDependOn)
{
    if(m_autoDependOn == autoDependOn)
        return;
    m_autoDependOn = autoDependOn;
    emit autoDependOnChanged(); ;
}

void QInstallerPackage::setPackageVirtual(const QString &packageVirtual)
{
    if(m_packageVirtual == packageVirtual )
        return;
    m_packageVirtual = packageVirtual ;
    emit packageVirtualChanged(); ;
}

void QInstallerPackage::setSortingPriority(const QString &sortingPriority)
{
    if(m_sortingPriority == sortingPriority )
        return;
    m_sortingPriority = sortingPriority ;
    emit sortingPriorityChanged() ;
}

void QInstallerPackage::setLicenses(const QString &licenses)
{
    if(m_licenses == licenses)
        return;
    m_licenses = licenses;
    emit licensesChanged(); ;
}

void QInstallerPackage::setScript(const QString &script)
{
    if(m_script == script )
        return;
    m_script = script;
    emit scriptChanged(); ;
}

void QInstallerPackage::setUserInterfaces(const QString &userInterfaces)
{
    if(m_userInterfaces == userInterfaces)
        return;
    m_userInterfaces = userInterfaces;
    emit userInterfacesChanged(); ;
}

void QInstallerPackage::setTranslations(const QString &translations)
{
    if(m_translations == translations)
        return;
    m_translations = translations;
    emit translationsChanged(); ;
}

void QInstallerPackage::setUpdateText(const QString &updateText)
{
    if(m_updateText == updateText)
        return;
    m_updateText = updateText;
    emit updateTextChanged(); ;
}

void QInstallerPackage::setPackageDefault(const QString &packageDefault)
{
    if(m_packageDefault == packageDefault)
        return;
    m_packageDefault = packageDefault;
    emit packageDefaultChanged(); ;
}

void QInstallerPackage::setEssential(const QString &essential)
{
    if(m_essential == essential)
        return;
    m_essential = essential;
    emit essentialChanged(); ;
}

void QInstallerPackage::setForcedInstallation(const QString &forcedInstallation)
{
    if(m_forcedInstallation == forcedInstallation)
        return;
    m_forcedInstallation = forcedInstallation;
    emit forcedInstallationChanged(); ;
}

void QInstallerPackage::setReplaces(const QString &replaces)
{
    if(m_replaces == replaces )
        return;
    m_replaces = replaces;
    emit replacesChanged();
}

void QInstallerPackage::setDownloadableArchives(const QString &downloadableArchives)
{
    if(m_downloadableArchives == downloadableArchives )
        return;
    m_downloadableArchives = downloadableArchives;
    emit downloadableArchivesChanged();
}

void QInstallerPackage::setRequiresAdminRights(const QString &requiresAdminRights)
{
    if(m_requiresAdminRights ==  requiresAdminRights)
        return;
    m_requiresAdminRights = requiresAdminRights;
    emit requiresAdminRightsChanged(); ;
}







/*******************************************************************************
 *  QDom and other functions that are needed to make each of the xml files and
 *  run all the qprocess things like binary creator and make static qt
 * ****************************************************************************/

QQMlDom::QQMlDom(QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(error(QString)),this,SLOT(handleError(QString)));
}

bool QQMlDom::staticBuild()
{
    return m_staticBuild;
}

void QQMlDom::setStaticBuild(const bool &staticBuild)
{
    if(m_staticBuild == staticBuild)
        return;
    m_staticBuild = staticBuild;
    emit staticBuildChanged();
}

void QQMlDom::downloadPrebuilt() const
{
     QSysInfo info;
//     QString downloadFile;
     QString os;
     os = info.kernelType();
//     QString arch = info.buildCpuArchitecture();

qDebug() << os;
//     if(os == "linux"){
//         qDebug() << linux
//     }else if (o)

//     switch (arch) {
//     case "x86_64":
//         downloadFile = "";
//         break;
//     case i386:
//         downloadFile = "";
//         break;

//     default:
//         break;
//     }




}

QStringList QQMlDom::getPrebuiltOptions()
{
    QStringList versions;
    versions.clear();
    versions << "2.0.1" << "2.0.0" << "1.5.0";
    return versions;
}

QString QQMlDom::binaryLoaction() const
{
    return m_binaryLocation;
}

bool QQMlDom::hasTheBinaryPath() const
{
    bool returnValue;
    QString binPath;
    QSettings settings("TheInstallerCompany","installerFrontend");
    settings.beginGroup("binaryPath");
    binPath = settings.value("binaryLocation").toString();
    settings.endGroup();

    if(binPath.isEmpty())
    {
        returnValue = false;
        //FIXME
        // some signal that emits a slot that makes the user fill out where the binarycreator is
    }
    else if (!binPath.isEmpty())
    {
        // FIXME
        // now just because we have the binPath in the settings
        // does not mean that it is on the users system
        // check with qfile later

        QFile bin(binPath);
        if (bin.exists())
        {
        returnValue = true;
        }
        else
        {
           returnValue = false;
//           error("Seems like your settings are missleading. Please re-setup where the binary path is located");
        }
    }
    return returnValue;
}

void QQMlDom::setBinaryCreatorLocation(const QString &binaryLoaction)
{

    if(m_binaryLocation == binaryLoaction)
    {
        return;
    }
    else
    {
        m_binaryLocation = binaryLoaction;
        //FIXME user qt namespace ?
        QSettings settings("TheInstallerCompany","installerFrontend");
        settings.beginGroup("binaryPath");
        settings.setValue("binaryLocation",m_binaryLocation);
        settings.endGroup();
        emit binaryLoactionChanged();
    }
}


//FIXME add path to where to add this
void QQMlDom::writeConfigPage(const QString path)
{
// create the default children nodes

   QDomElement rootInstaller = m_document.createElement("Installer");
   m_document.appendChild(rootInstaller);


   QStringList nodeLists ;
   nodeLists << getDefaultConfigXml();

    for (int i = 0 ; i < nodeLists.length();i++){
        QDomElement configNodes = m_document.createElement(nodeLists.at(i));
        rootInstaller.appendChild(configNodes);
    }

    createNewNode(m_document,rootInstaller,"RunProgramArguments","Argument");
    createNewNode(m_document,rootInstaller,"RemoteRepositories","Repository");
    createNewNode(m_document,rootInstaller,"Repository","Url");

    // Now Finaly write it all to a file.
   QString installerPath = QString("%1%2").arg(path).arg("/config.xml");
   QFile instalerFile(installerPath);

   // Create the root node
   if ( ! instalerFile.open(QFile::WriteOnly | QFile::Text) )
   {
       error("Could not open the Installer Configure File IE config.xml");
   }else{
       QTextStream stream(&instalerFile);
       stream << m_document.toString();
       instalerFile.close();

   }

}

void QQMlDom::writePackagePage(const QString path)
{

    m_document.clear();
    QDomElement packageInstaller = m_document.createElement("Package");
    m_document.appendChild(packageInstaller);


    QStringList nodeLists ;
    nodeLists << getDefaultPackageXml();

     for (int i = 0 ; i < nodeLists.length();i++){
         QDomElement packageNodes = m_document.createElement(nodeLists.at(i));
         packageInstaller.appendChild(packageNodes);
     }
     createNewNode(m_document,packageInstaller,"Licenses","License");
     createNewNode(m_document,packageInstaller,"UserInterfaces","UserInterface");
     createNewNode(m_document,packageInstaller,"Translations","Translation");


     // Now Finaly write it all to a file.
    QString installerPath = QString("%1%2").arg(path).arg("/package.xml");
    QFile instalerFile(installerPath);

    // Create the root node
    if ( ! instalerFile.open(QFile::WriteOnly | QFile::Text) )
    {
        error("Could not open the Installer Configure File IE package.xml");
    }else{
        QTextStream stream(&instalerFile);
        stream << m_document.toString();
        instalerFile.close();
    }
}

void QQMlDom::checkConfigManditory(const QString &element,const QString text)
{
    if (element.length() <= 0 ){
            error("");
    }else{
        addependTextById(m_document,element,text);
    }
}

bool QQMlDom::dirExists(const QString dir)
{
    qDebug() << dir;
    QDir d(dir);
    if(d.exists()){
        return true;
    }else{
        return false;
    }
}

void QQMlDom::copyBinary()
{
    qDebug() << "NaN";
}

void QQMlDom::mkDefaultDirs(const QString rootDir,const QString projectName,const QString appName)
{
    QString configDir = QString("%1/%2").arg(rootDir).arg("config");
    QString pDir  = QString ("%1/%2/%3").arg(rootDir).arg(projectName).arg("meta");
    QString online = QString("%1/%2").arg(rootDir).arg("package_update");
    QString resource = QString("%1/%2").arg(rootDir).arg("resource");

    //    qDebug() << configDir;
    //    qDebug() << pDir;
    //    qDebug() << rootDir;

    QDir dir(rootDir);

    if ( !dir.exists() )
    {
        if( !dir.mkpath(rootDir) )
        {
            error("could not make root dir");
        }

        if( !dir.mkpath(configDir) )
        {
            error("could not make the confiure dir");
        }

        if( !dir.mkpath(pDir) )
        {
            error("could not make package dir");
        }

        if( !dir.mkpath(online))
        {
            error("could not make online dir");
        }


        if( !dir.mkpath(resource))
        {
            error("could not make online dir");
        }



        //  make the files
        // FIXME make these bool and not void
        makeProFile(rootDir,appName);
        makeConfigFile(configDir,"config.xml");
        makePackageFile(pDir,"package.xml");
        makeQSFile(pDir,"installscript.qs");
        makeLicenseFile(pDir,"license.txt");
        makeREADMEFile(rootDir,"README");

        //        now  write to the confi.xml and also the package.xml
        writeConfigPage(configDir);
        writePackagePage(pDir);
    }else{
        error("Root Dir is already there Mybe you want to alter it ?");
    }
}

// This is used to create another sub component default layout
bool QQMlDom::createSubPackageComponent()
{
    return false;
}

QStringList QQMlDom::getDefaultConfigXml()
{
    QList<QString> nodeList;
    nodeList <<
                "Name" << "Version" << "Title" << "Publisher" << "ProductUrl" << "Icon" << "InstallerApplicationIcon"
             << "InstallerWindowIcon" << "Logo" << "Watermark" << "Banner" << "Background" << "WizardStyle" << "WizardDefaultWidth"
             << "WizardDefaultHeight" << "TitleColor" << "RunProgram" << "RunProgramArguments" << "RunProgramDescription"
             << "StartMenuDir" << "TargetDir" << "AdminTargetDir" << "RemoteRepositories" << "MaintenanceToolName"
             << "MaintenanceToolIniFile" <<  "RemoveTargetDir" << "AllowNonAsciiCharacters" << "RepositorySettingsPageVisible"
             << "AllowSpaceInPath" << "DependsOnLocalInstallerBinary" << "TargetConfigurationFile" << "Translations" << "UrlQueryString"
             << "ControlScript" << "CreateLocalRepository" ;
    return nodeList;
}

QStringList QQMlDom::getDefaultPackageXml()
{
    QStringList defaultPackageXml ;
    defaultPackageXml <<"DisplayName" <<"Description" <<"Version" <<"ReleaseDate" <<"Name" <<"Dependencies" <<"AutoDependOn" <<"Virtual"
    <<"SortingPriority" <<"Licenses" <<"Script" <<"UserInterfaces" <<"Translations" <<"UpdateText" <<"Default"
    <<"Essential" <<"ForcedInstallation" <<"Replaces" <<"DownloadableArchives" <<"RequiresAdminRights";
    return defaultPackageXml;
}

void QQMlDom::makeProFile(const QString rootDir, const QString projectName)
{

    // This is the Default Templete not the end product
    QStringList proTemplete;
            proTemplete << "TEMPLATE = aux" <<  "INSTALLER = installer" <<  "INPUT = $$PWD/config/config.xml $$PWD/packages"
                        << "example.input = INPUT" << "example.output = $$INSTALLER" <<  "example.commands = binarycreator -c $$PWD/config/config.xml -p $$PWD/packages ${QMAKE_FILE_OUT}"
                        << "example.CONFIG += target_predeps no_link combine" <<  "QMAKE_EXTRA_COMPILERS += example"
                        << "OTHER_FILES = README";

    QString proFileCanonical = QString("%1/%2%3").arg(rootDir,projectName).arg(".pro");


//    qDebug() << proFileCanonical;

    QFile f(proFileCanonical);
    if(f.open(QFile::WriteOnly|QFile::Text)){
    QTextStream in(&f);
    for (int i = 0 ; i < proTemplete.length(); i++){
        in << proTemplete.at(i);
        in << "\n";
    }
    }else{
        error("Could not open the profile to write to") ;
    }

}

void QQMlDom::makeConfigFile(const QString rootDir, const QString projectName)
{
    QString path = QString("%1/%2").arg(rootDir).arg(projectName);
    qDebug() << path;
    QFile f(path);
    if(f.open(QFile::WriteOnly|QFile::Text)){
//        qDebug() << "Created the Config.xml file";
    }else{
        qDebug() << "Could not open the profile to write to" ;
    }

}

void QQMlDom::makePackageFile(const QString rootDir, const QString projectName)
{
    QString path = QString("%1/%2").arg(rootDir).arg(projectName);
    qDebug() << path;
    QFile f(path);
    if(f.open(QFile::WriteOnly|QFile::Text)){
//        qDebug() << "Created the package.xml file";
    }else{
        error("Could not open the profile to write to");
    }
}

void QQMlDom::makeREADMEFile(const QString rootDir, const QString projectName)
{
    QString path = QString("%1/%2").arg(rootDir).arg(projectName);
    qDebug() << path;
    QFile f(path);
    if(f.open(QFile::WriteOnly|QFile::Text)){
//        qDebug() << "Created the README file";
    }else{
        error("Could not open the profile to write to") ;
    }
}

void QQMlDom::makeQSFile(const QString rootDir, const QString projectName)
{
    QString path = QString("%1/%2").arg(rootDir).arg(projectName);
    qDebug() << path;
    QFile f(path);
    if(f.open(QFile::WriteOnly|QFile::Text)){
//        qDebug() << "Created the installer.qs file";
    }else{
        error("Could not open the profile to write to") ;
    }
}

void QQMlDom::makeLicenseFile(const QString rootDir, const QString projectName)
{
    QString path = QString("%1/%2").arg(rootDir).arg(projectName);
    qDebug() << path;
    QFile f(path);
    if(f.open(QFile::WriteOnly|QFile::Text)){
//        qDebug() << "Created the license.txt file";
    }else{
        error("Could not open the profile to write to") ;
    }
}

void QQMlDom::addependTextById(QDomDocument nDocument, QString element, QString text)
{

    QDomElement root = nDocument.documentElement();
    QDomNodeList nList = root.elementsByTagName(element);
    QDomNode nNode = nList.at(0);
    QDomElement nodeTag =  nNode.toElement();

    // create a new node with a QDomText child
    QDomElement newNodeTag = nDocument.createElement(QString(element));
    QDomText newNodeText = nDocument.createTextNode(QString(text));
    newNodeTag.appendChild(newNodeText);

    // replace existing node with new node
    root.replaceChild(newNodeTag, nodeTag);

}

void QQMlDom::addependAttributeById(QDomElement nDocument, QString element, QString attribute)
{
    QDomNodeList appendList = nDocument.elementsByTagName(element);
    QDomNode aUrl = appendList.at(0);
    QDomElement appender = aUrl.toElement();

    // This makes atributes.  How to make
    appender.setAttribute(element,attribute);
}

void QQMlDom::createNewNode(QDomDocument nDocument , QDomElement nElement, QString parent, QString nodeName)
{

    QDomNodeList nList = nElement.elementsByTagName(parent);
    QDomNode nNode = nList.at(0);
    QDomElement nnElement = nNode.toElement();
    QDomElement newElement = nDocument.createElement(nodeName);
    nnElement.appendChild(newElement);
}

void QQMlDom::removeDefaultNode(QDomElement nDocument, QString element)
{
    QDomNodeList removeList = nDocument.elementsByTagName(element);
    QDomNode rUrl = removeList.at(0);
    qDebug() << "is there a child node ?"  << rUrl.hasChildNodes() <<"  " << rUrl.childNodes().at(0).nodeName() ;
    rUrl.removeChild(rUrl.childNodes().at(0));
}

void QQMlDom::removeNodeById(QDomElement nDocument, QString element)
{
    QDomNodeList removeList = nDocument.elementsByTagName(element);
    QDomNode rUrl = removeList.at(0);
    QDomNode rrUrl = rUrl.parentNode();
    qDebug() << "is there a child node ?"  << rrUrl.hasChildNodes() <<"  " << rrUrl.childNodes().at(0).nodeName() ;
    rrUrl.removeChild(rrUrl.childNodes().at(0));
}

void QQMlDom::handleError(const QString err)
{
    //FIXME make errorString
    qDebug() << err;
}

