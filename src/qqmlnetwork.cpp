/*
 * Copyright (C) 2014 Joseph Mills.
 *
 */
#include <QFileInfo>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QStringList>
#include <QTimer>
#include <stdio.h>
#include "qqmlnetwork.h"


QQmlNetwork::QQmlNetwork(QObject *parent)
    : QObject(parent),
      m_multiFiles(false),
      m_type(Get),
      m_status(Default),
      m_networkError(NoError)

{

    connect(this,SIGNAL(error(QString)),this,SLOT(handelError(QString)));
}

QQmlNetwork::Type QQmlNetwork::type() const
{
    return m_type;
}

void QQmlNetwork::setType(const QQmlNetwork::Type &type)
{
    if(m_type == type)
        return;
    m_type = type;
    emit typeChanged();
}

QQmlNetwork::Status QQmlNetwork::status()
{
    return m_status;
}

void QQmlNetwork::setStatus(const QQmlNetwork::Status &status)
{
    if (m_status == status)
        return;
    m_status = status;
    emit statusChanged();
}

QQmlNetwork::NetworkError QQmlNetwork::networkError()
{
    return m_networkError;
}

void QQmlNetwork::setNetworkError(QNetworkReply::NetworkError networkError)
{
    if (networkError == QNetworkReply::NoError)
    {
        if (m_networkError == NoError)
            return;
        m_networkError = NoError;
        emit networkErrorChanged();
    }
    else if (networkError == QNetworkReply::ConnectionRefusedError)
    {
        if (m_networkError == ConnectionRefused)
            return;
        m_networkError = ConnectionRefused;
        emit networkErrorChanged();
    }
    else if (networkError == QNetworkReply::RemoteHostClosedError)
    {
        if (m_networkError == RemoteHostClosed)
            return;
        m_networkError = RemoteHostClosed;
        emit networkErrorChanged();
    }
    else if (networkError == QNetworkReply::HostNotFoundError)
    {
        if (m_networkError == HostNotFound)
            return;
        m_networkError = HostNotFound;
        emit netwrokErrorChanged();
    }
    else if ( networkError == QNetworkReply::UnknownServerError)
    {
        if (m_networkError == UnknownServer)
            return;
        m_networkError = UnknownServer;
        emit networkErrorChanged();
    }
}

void QQmlNetwork::handelFinsished(QNetworkReply *reply)
{
    qDebug() << reply;
}

void QQmlNetwork::handelError(QString err)
{
    setErrorString(err);
}

void QQmlNetwork::checkRedirection(QNetworkReply *reply)
{
//    qDebug() << "READ ALL  " << reply->readAll();

    if (reply->error() == QNetworkReply::NoError) {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        switch (statusCode) {
        case 301:
        case 302:
        case 307:
            QUrl redirection;
            redirection = reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
            output.close();
            qDebug() << "GOT REDIRECTION TO " << redirection;
            downloadQueue.clear();
            append(redirection);
//            downloadQueue.enqueue(redirection);
//            startNextDownload();
            break;
//        case 200:
//            qDebug() << "200 " << reply->readAll();
//            break;
//        case 404:
//            qDebug() << "404 Oh No ";
//            break;
        }
    }
    reply->deleteLater();
}


void QQmlNetwork::urlList(const QStringList &urlList)
{
    foreach (QString url, urlList)
        append(QUrl::fromEncoded(url.toLocal8Bit()));

    if (downloadQueue.isEmpty())
    {
        QTimer::singleShot(0, this, SIGNAL(finished()));
    }
}

void QQmlNetwork::append(const QUrl &url)
{
    if (downloadQueue.isEmpty()){
        QTimer::singleShot(0, this, SLOT(startNextDownload()));
    }
    downloadQueue.enqueue(url);
    ++totalCount;
}


void QQmlNetwork::execute()
{
    if(m_type == Get){
        if(m_multiFiles == false)
        {
            append(m_url);
        }
        else
        {
            // run multifiles
            if (m_urls.length() < 0 )
            {
                error("You must set a couple of files to download");
                return;
            }
            else if ( m_urls.length() > 0 )
            {
                urlList(m_urls);
            }
        }
    }
    else if (m_type == Put)
    {

    }
    else if (m_type == Post)
    {

    }else if (m_type == Delete)
    {

    }else if (m_type == Custom)
    {

    }
}


QString QQmlNetwork::url()
{
    return m_url;
}

void QQmlNetwork::setUrl(const QString &url)
{
    if(m_url == url)
        return;
    m_url = url;
    emit urlChanged();
}


QString QQmlNetwork::savePath()
{
    return m_path;
}

void QQmlNetwork::setSavePath(const QString &savePath)
{
    if(m_path == savePath)
        return;
    m_path = savePath;
    emit savePathChanged();
}

QString QQmlNetwork::savedFile()
{
    return m_savedFile;
}

void QQmlNetwork::setSavedFileName(const QString savedFile)
{
    if(m_savedFile == savedFile)
        return;
    m_savedFile = savedFile;
    // emit ?  who cares  ?
}


QString QQmlNetwork::saveFileName(const QString &downloadFile)
{
    return  downloadFile;
}


quint64 QQmlNetwork::bytesReceived()
{
    return m_bytesReceived;
}

void QQmlNetwork::setBytesRecived(const quint64 &bytesReceived)
{

    m_bytesReceived = bytesReceived;
    emit  bytesReceivedChanged();
}


quint64 QQmlNetwork::bytesTotal()
{
    return m_bytesTotal;
}

void QQmlNetwork::setBytesTotal(const quint64 &bytesTotal)
{
    m_bytesTotal = bytesTotal;
    emit bytesTotalChanged();
}

QString QQmlNetwork::reply()
{
    return m_reply;
}

void QQmlNetwork::setReply(const QString reply)
{
    if(m_reply == reply)
        return;
    m_reply = reply;
    emit replyChanged();
}



QString QQmlNetwork::errorString()
{
    return m_error;
}

void QQmlNetwork::setErrorString(const QString &errorString)
{
    m_error == errorString;
}

void QQmlNetwork::redirectUrl(const QString &possibleRedirectUrl)
{
    qDebug() << possibleRedirectUrl;
}


QString QQmlNetwork::units()
{
    return m_units;
}

void QQmlNetwork::setUnits(const QString &units)
{
    if (m_units == units)
        return;
    m_units = units;
    emit unitsChanged();
}


double QQmlNetwork::incommingSpeed()
{
    return m_speed;
}

void QQmlNetwork::setincommingSpeed(const double &incommingSpeed)
{
    if(m_speed == incommingSpeed)
        return;
    m_speed = incommingSpeed;
    emit incommingSpeedChanged();
}


void QQmlNetwork::startNextDownload()
{
    if (downloadQueue.isEmpty()) {
//        qDebug() << downloadedCount << " " << totalCount << "files downloaded successfully\n";
        emit finished();
        return;
    }
    QUrl url = downloadQueue.dequeue();
    QFileInfo fileInf(url.toString());
    QString fileName = QString("%1%2").arg(m_path).arg(fileInf.fileName());




    setSavedFileName(fileName);
//    qDebug() << fileName;
    output.setFileName(fileName);

    if (output.exists()){
        if(output.remove())
        {
            qDebug() << "removed the old file";
        }
    }



    if (!output.open(QIODevice::WriteOnly)) {
        error("Problem opening save file for download");
        startNextDownload();
        return;
    }

    qDebug() << "GOING TO TRY AND DOWNLOAD " << url;

    QNetworkRequest request(url);
    currentDownload = manager.get(request);

    // FIX ME check for redirection
    connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(checkRedirection(QNetworkReply*)));

    connect(currentDownload, SIGNAL(downloadProgress(qint64,qint64)), SLOT(downloadProgress(qint64,qint64)));
    connect(currentDownload, SIGNAL(finished()), SLOT(downloadFinished()));
    connect(currentDownload, SIGNAL(readyRead()), SLOT(downloadReadyRead()));
    connect(currentDownload,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(setNetworkError(QNetworkReply::NetworkError)));


    downloadTime.start();

}


void QQmlNetwork::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    double speed = bytesReceived * 1000.0 / downloadTime.elapsed();
    QString unit;
    if (speed < 1024) {
        unit = "bytes/sec";
    } else if (speed < 1024*1024) {
        speed /= 1024;
        unit = "kB/s";
    } else {
        speed /= 1024*1024;
        unit = "MB/s";
    }
    setBytesRecived(bytesReceived);
    setincommingSpeed(speed);
    setUnits(unit);
    setBytesTotal(bytesTotal);

}


void QQmlNetwork::downloadFinished()
{


    if (currentDownload->error()) {
        // download failed
        setErrorString("Failed " + currentDownload->errorString());
    } else {
        qDebug() << "Succeeded. Downloading " << m_path;
        if (downloadQueue.isEmpty()){
            output.write(currentDownload->readAll());
            output.close();
            emit finished();
        }
    }
    // FIXME delete this somewhere
    currentDownload->deleteLater();
}

void QQmlNetwork::downloadReadyRead()
{

//    /*
//      * Reply is finished!
//      * We'll ask for the reply about the Redirection attribute
//      * http://doc.trolltech.com/qnetworkrequest.html#Attribute-enum
//      */
//     QVariant possibleRedirectUrl =
//              reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

//     /* We'll deduct if the redirection is valid in the redirectUrl function */
//     _urlRedirectedTo = this->redirectUrl(possibleRedirectUrl.toUrl(),
//                                          _urlRedirectedTo);

//     /* If the URL is not empty, we're being redirected. */
//     if(!_urlRedirectedTo.isEmpty()) {
//         QString text = QString("QQmlNetwork::replyFinished: Redirected to ")
//                               .append(_urlRedirectedTo.toString());
//         qDebug()<< text;
////         this->_textContainer->setText(text);

//         /* We'll do another request to the redirection url. */
////         this->_qnam->get(QNetworkRequest(_urlRedirectedTo));
//     }
//     else {
//         /*
//          * We weren't redirected anymore
//          * so we arrived to the final destination...
//          */
//         QString text = QString("QQmlNetwork::replyFinished: Arrived to ")
//                               .append(reply->url().toString());
//         qDebug() <<text;
//         /* ...so this can be cleared. */
////         _urlRedirectedTo.clear();
////         output.write(currentDownload->readAll());
//     }
//     /* Clean up. */
////     reply->deleteLater();




//    //
}


QStringList QQmlNetwork::urls() const
{
    return m_urls;
}


void QQmlNetwork::setUrls(const QStringList &urls)
{
    if(m_urls == urls)
        return;
    m_urls = urls;
    emit urlsChanged();
}

bool QQmlNetwork::multiFiles() const
{
    return m_multiFiles;
}

void QQmlNetwork::setMultiFiles(const bool &multiFiles)
{
    if(m_multiFiles == multiFiles)
        return;
    m_multiFiles = multiFiles;
    emit multiFilesChanged();
}
