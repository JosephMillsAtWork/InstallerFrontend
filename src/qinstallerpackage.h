#ifndef QINSTALLERPACKAGE_H
#define QINSTALLERPACKAGE_H

#include <QObject>

class QInstallerPackage : public QObject
{

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


#endif // QINSTALLERPACKAGE_H
