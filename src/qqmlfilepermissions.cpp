#include "qqmlfilepermissions.h"

QQmlFilePermissions::QQmlFilePermissions(QObject *parent) :
    QObject(parent)
{
}

QString QQmlFilePermissions::file() const
{
    return m_file;
}

void QQmlFilePermissions::setFile(const QString &file)
{
    if(m_file == file)
        return;
    m_file = file;
    emit fileChanged();
}

void QQmlFilePermissions::checkPermissions()
{
    // some test file
    if(m_file.isEmpty()){
        qDebug() << "Error you must set a file";
    }else{

        QStringList currentPermissions;
        QFile f(m_file);
        if(f.exists()){

            QFileDevice::Permissions p = QFile(m_file).permissions();
            qDebug() << p ;

            // +r
            if (p & QFileDevice::ReadOwner)
            {
                qDebug() << "File is READ OWNER ";
                currentPermissions.append("ReadOwner");
            }
            if (p & QFileDevice::ReadOther){
                qDebug() << "FILE IS READ OTHER ";
                currentPermissions.append("ReadOther");
            }
            if (p & QFileDevice::ReadGroup){
                qDebug() << "FILE IS READ GROUP";
                currentPermissions.append("ReadGroup");
            }

            // +w
            if (p & QFileDevice::WriteOther){
                qDebug() << "The file is Write Other ";
                currentPermissions.append("WriteOther");
            }
            if (p & QFileDevice::WriteOwner){
                qDebug() << "File is Write Owner";
                currentPermissions.append("WriteOwner");
            }
            if (p & QFileDevice::WriteGroup){
                qDebug() << "File is Write Group ";
                currentPermissions.append("WriteGroup");
            }

            // +x
            if (p & QFileDevice::ExeGroup){
                qDebug() << "file is exec group";
                currentPermissions.append("ExeGroup");
            }
            if (p & QFileDevice::ExeOwner){
                qDebug() << "file is exec owner";
                currentPermissions.append("ExeOwner");
            }
            if (p & QFileDevice::ExeOther){
                qDebug() << "file is exec other";
                currentPermissions.append("ExeOther");
            }

            setCurrentPermissions(currentPermissions);
        }else{
            qDebug() << "There is no such file called "<< f.fileName();
        }
    }

}

void QQmlFilePermissions::setCurrentPermissions(const QStringList list)
{
    if (m_currentPermissions == list )
        return;
    m_currentPermissions = list;
    // emit later
}

void QQmlFilePermissions::appendPermissions(const QQmlFilePermissions::Permissions permissions)
{
    checkPermissions();

    if (m_currentPermissions.isEmpty()){
        qDebug() << "there is no permissions on this file " << m_file ;
    }


    // set the old permissions
    QFile f(m_file);








    // read
    if (m_permissions.contains("ReadOther",Qt::CaseSensitive) || permissions == ReadOther){
        f.setPermissions(QFileDevice::ReadOther);
    }
    if (m_permissions.contains("ReadOwner",Qt::CaseSensitive) || permissions == ReadOwner){
        f.setPermissions(QFileDevice::ReadOwner);
    }
    if (m_permissions.contains("ReadGroup",Qt::CaseSensitive) || permissions == ReadGroup){
        f.setPermissions(QFileDevice::ReadGroup);
    }
    // write
    if (m_permissions.contains("WriteOther",Qt::CaseSensitive) || permissions == WriteOther){
        f.setPermissions(QFileDevice::WriteOther);
    }
    if (m_permissions.contains("WriteOwner",Qt::CaseSensitive)|| permissions == WriteOwner){
        f.setPermissions(QFileDevice::WriteOwner);
    }
    if (m_permissions.contains("WriteGroup",Qt::CaseSensitive)|| permissions == WriteGroup){
        f.setPermissions(QFileDevice::WriteGroup);
    }
    // exceute
    if (m_permissions.contains("ExeOther",Qt::CaseSensitive) || permissions == ExecOther){
        f.setPermissions(QFileDevice::ExeOther);
    }
    if (m_permissions.contains("ExeOwner",Qt::CaseSensitive) || permissions == ExecOwner){
        f.setPermissions(QFileDevice::ExeOwner);
    }
    if (m_permissions.contains("ExeGroup",Qt::CaseSensitive) || permissions == ExecGroup){
        f.setPermissions(QFileDevice::ExeGroup);
    }
}
