#include "qinstallerpackage.h"


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


