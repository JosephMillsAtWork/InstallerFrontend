#ifndef QNETWORKSCANNER_H
#define QNETWORKSCANNER_H

#include<QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QList>

class QNetworkScanner : public QObject
{
    Q_OBJECT
public:
    explicit QNetworkScanner(QObject *parent = 0);

//    void setUrl(const QString &url);
//    QString scanDir();

    Q_INVOKABLE void getRootReply();

signals:

public slots:
    void replyFinished(QNetworkReply* reply);
//    void handelErrors(QNetworkReply::NetworkError reply);
void replayFinished();
void replyError(QNetworkReply::NetworkError err);
//    void accessinlityChanged(QNetworkAccessManager::NetworkAccessibility networkAccess);
private:
    QNetworkAccessManager *m_manager;
    QNetworkReply *m_reply;

};

#endif // QNETWORKSCANNER_H
