#include "qnetworkscanner.h"
#include <QEventLoop>
QNetworkScanner::QNetworkScanner(QObject *parent) :
    QObject(parent)
{

    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(replyFinished(QNetworkReply*)));
}

void QNetworkScanner::getRootReply()
{
//    QUrl url = QUrl("https://download.qt.io/official_releases/qt-installer-framework/");
    QUrl url = QUrl("http://www.qt.io/");
    QNetworkRequest m_request(url);

    qDebug() << "Trying to get the needed reply";
    m_reply = m_manager->get(m_request);
    qDebug() << "Request Sent";
    connect(m_reply,SIGNAL(readyRead()),this,SLOT(replayFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(replyError(QNetworkReply::NetworkError)));

}

void QNetworkScanner::replyFinished(QNetworkReply* reply)
{
    qDebug() << "Finshed ";
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "ERROR \n" << reply->error();
    }
    else
    {
        qDebug() << "Running ParserResponse for \n" << reply->readAll();

    }
}

void QNetworkScanner::replayFinished()
{
    qDebug() << "replayFinished";
}

void QNetworkScanner::replyError(QNetworkReply::NetworkError err)
{
    qDebug() << "replyError " << err ;
}

//void QNetworkScanner::handelErrors(QNetworkReply::NetworkError reply)
//{
//    QString err = reply.errorString();
//    qDebug() << err;
//}


