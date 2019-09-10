#ifndef HTTPDOWNLOADRESUME_H
#define HTTPDOWNLOADRESUME_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

enum DownLoadStatus
{
    StateHead = 0,
    StateCheck,      //檢查狀態碼,是否出錯,是否重定向
    StateDownload
};

class HttpDownloadResume : public QObject
{
    Q_OBJECT
public:
    explicit HttpDownloadResume(QObject *parent = nullptr);

signals:

public slots:
    void onLoadFinished();
    void onDownloadProgress(qint64 cur, qint64 total);

private:
    QNetworkAccessManager mgr;
    DownLoadStatus state;
    int fileSize;
    QString URL = "http://cdn.atgamescloud.com/retro-apps/production/AppVersion/ha8800_test/10/ha8800_0.9.100.img?ttl=1568108934&sig=b5a5bfe3d5ad62305bba9ce531695742";
};

#endif // HTTPDOWNLOADRESUME_H
