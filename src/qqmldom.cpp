#include "qqmldom.h"

QQMlDom::QQMlDom(QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(error(QString)),this,SLOT(handleError(QString)));
}

QString QQMlDom::errorString()
{
    return m_errorString;
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

void QQMlDom::downloadPrebuilt(const QString version)
{
    QSysInfo info;
    QString os;
    QString system;
    os = info.kernelType().toLatin1();
    QString arch = info.buildCpuArchitecture();

    if (os == "darwin")
    {
        system = "mac";
    }
    else if ( os == "linux")
    {
        if(arch == "x86_64"){
            system = "linux64";
            qDebug() << "Suggested Donload  qt-installer-framework-opensource-2.0.1-x64.run";
        }
        //FIXME error check for arm and what not
        else
        {
            system = "linux32";
            qDebug() << "Suggested Donload  qt-installer-framework-opensource-2.0.1-x86.run";
        }
    }
    else if (os == "wince" || os == "winnt")
    {
        system = "doz";
    }
}


QStringList QQMlDom::getPrebuiltOptions()
{
    QStringList versions;
    versions.clear();
    versions << "2.0.1" << "2.0.0";
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
    defaultPackageXml <<
                 "DisplayName" << "Description" << "Version" << "ReleaseDate" << "Name" << "Dependencies" << "AutoDependOn" << "Virtual"
              << "SortingPriority" << "Licenses" << "Script" << "UserInterfaces" << "Translations" << "UpdateText" << "Default"
              << "Essential" << "ForcedInstallation" << "Replaces" << "DownloadableArchives" << "RequiresAdminRights";
    return defaultPackageXml;
}

void QQMlDom::makeProFile(const QString rootDir, const QString projectName)
{

    // This is the Default Templete not the end product
    QStringList proTemplete;
            proTemplete <<
                        "TEMPLATE = aux" <<  "INSTALLER = installer" <<  "INPUT = $$PWD/config/config.xml $$PWD/packages"
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
    if(m_errorString == err )
        return;
    m_errorString = err;
    emit errorStringChanged();
}

