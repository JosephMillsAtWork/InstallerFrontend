#ifndef QQMLFILEPERMISSIONS_H
#define QQMLFILEPERMISSIONS_H

#include <QObject>
#include <QFile>
#include <QFileDevice>
#include <QDebug>
#include <QStringList>

class QQmlFilePermissions : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString file READ file WRITE setFile NOTIFY fileChanged)
    Q_ENUMS(Permissions)

public:
    explicit QQmlFilePermissions(QObject *parent = 0);

    enum Permissions {
        ReadOther,
        ReadOwner,
        ReadGroup,
        WriteOther,
        WriteOwner,
        WriteGroup,
        ExecOther,
        ExecOwner,
        ExecGroup
    };


    QString file()const;
    void setFile(const QString &file);
    void setCurrentPermissions(const QStringList list);


    void checkPermissions();
    Q_INVOKABLE void appendPermissions(const Permissions permissions);


signals:
        void fileChanged();
public slots:

private:
    QString m_permissions;
    QString m_file;
    QStringList m_currentPermissions;

};

#endif // QQMLFILEPERMISSIONS_H
