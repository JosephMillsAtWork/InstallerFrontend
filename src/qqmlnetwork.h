#ifndef QQMLNETWORK_H
#define QQMLNETWORK_H

#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QSsl>
#include <QObject>
#include <QQueue>
#include <QTime>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>


class QQmlNetwork: public QObject
{
    Q_OBJECT


    // SETUP
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged )
    // Multi download upload ect
    Q_PROPERTY(QStringList urls READ urls WRITE setUrls NOTIFY urlsChanged)
    Q_PROPERTY(bool multiFiles READ multiFiles WRITE setMultiFiles NOTIFY multiFilesChanged)

    //Error Handle
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorStringChanged)

    //Downloads (GET)
    Q_PROPERTY(QString savePath READ savePath WRITE setSavePath)
    Q_PROPERTY(QString savedFile READ savedFile NOTIFY savedFileChanged)
    Q_PROPERTY(quint64 bytesReceived READ bytesReceived NOTIFY bytesReceivedChanged)
    Q_PROPERTY(quint64 bytesTotal READ bytesTotal NOTIFY bytesTotalChanged)
    Q_PROPERTY(QString units READ units NOTIFY unitsChanged )
    Q_PROPERTY(double incommingSpeed READ incommingSpeed NOTIFY incommingSpeedChanged)


    //PUT

    //POST
    Q_PROPERTY(QString reply READ reply WRITE setReply NOTIFY replyChanged)


//    setHeader
//  QStringList  setAttributes
    //bool bufferuplpoad data
    // KnownHeaders knownHeaders
    // LoadControl
    // cache load control
    // prority // gies to main settings ?




    //CUSTOM

    //DELETE

    //ENUMS
    Q_PROPERTY(Type type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(Status status READ status NOTIFY statusChanged)
    Q_PROPERTY(NetworkError networkError READ networkError NOTIFY networkErrorChanged)
    Q_ENUMS(Type)
    Q_ENUMS(Status)
    Q_ENUMS(NetworkError)


public:
    QQmlNetwork(QObject *parent = 0);

    enum Type{
        Put,
        Get,
        Post,
        Delete,
        Custom
    };
    Type type()const;
    void setType(const Type &type);

    enum Status{
        Default,
        Started,
        Running,
        ReadReady,
        Finished,
    };
    Status status();
    void setStatus(const Status &status);

    enum NetworkError{
        NoError,
        ConnectionRefused,
        RemoteHostClosed,
        HostNotFound,
        UnknownServer
    };
    NetworkError networkError();






    // Run all this
    Q_INVOKABLE void execute();

    QString url();
    void setUrl(const QString &url);

    QStringList urls()const;
    void setUrls(const QStringList &urls);

    bool multiFiles()const;
    void setMultiFiles(const bool &multiFiles);

    void append(const QUrl &url);
    void urlList(const QStringList &urlList);

    // GET
    QString savePath();
    void setSavePath(const QString &savePath);

    QString savedFile();
    void setSavedFileName(const QString savedFile);

    QString saveFileName(const QString &downloadFile);
    quint64 bytesReceived();
    void setBytesRecived(const quint64  &bytesReceived);
    QString units();
    void setUnits(const QString &units);
    double incommingSpeed();
    void setincommingSpeed(const double &incommingSpeed);
    quint64 bytesTotal();
    void setBytesTotal(const quint64 &bytesTotal);

    // PUT

    // POST
    QString reply();
    void setReply(const QString reply);
    // Delete

    // Custom

    //Error
    QString errorString();
    void setErrorString(const QString &errorString);


    void redirectUrl(const QString &possibleRedirectUrl);


signals:
    void finished();
    void incommingSpeedChanged();
    void bytesReceivedChanged();
    void unitsChanged();
    void bytesTotalChanged();
    void errorStringChanged();
    void fileChanged();
    void savePathChanged();
    void savedFileChanged();
    void typeChanged();
    void statusChanged();
    void netwrokErrorChanged();
    void urlChanged();
    void urlsChanged();
    void multiFilesChanged();
    void replyChanged();
    void networkErrorChanged();

    void error(QString);
private slots:
    void startNextDownload();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void downloadFinished();
    void downloadReadyRead();
    void setNetworkError(QNetworkReply::NetworkError networkError);
    void handelFinsished(QNetworkReply *reply);
    void handelError(QString err);
    void checkRedirection(QNetworkReply *reply);
private:
    QNetworkAccessManager manager;
    QQueue<QUrl> downloadQueue;
    QNetworkReply *currentDownload;
    QFile output;
    QString m_url;
    QStringList m_urls;
    bool m_multiFiles;


    QString m_path;
    QTime downloadTime;
    QString m_savedFile;

    int downloadedCount;
    int totalCount;

    // fro progression
    qint64 m_bytesReceived;
    qint64 m_bytesTotal;
    QString m_units;
    double m_speed;

    // post
    QString m_reply;

    //error checking
    QString m_error;


    //enum
    Type m_type;
    Status m_status;
    NetworkError m_networkError;
};

#endif
