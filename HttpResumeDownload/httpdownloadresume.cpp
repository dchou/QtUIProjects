#include "httpdownloadresume.h"
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

HttpDownloadResume::HttpDownloadResume(QObject *parent) : QObject(parent)
{
    fileSize = 0;
    state = StateHead;

    QNetworkRequest request;
    //DC request.setUrl(QUrl("http://download.qt.io/official_releases/qt/5.13/5.13.1/qt-opensource-mac-x64-5.13.1.dmg"));
    request.setUrl(QUrl(URL));
    QNetworkReply *reply = mgr.head(request);
    connect(reply, SIGNAL(finished()), this, SLOT(onLoadFinished()));
}

void HttpDownloadResume::onLoadFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(this->sender());
    if (reply == NULL)
        return;

    if (state == StateHead)
    {
        fileSize = reply->rawHeader("Content-Length").toInt();
        qDebug() << "file size: " << fileSize;

        QNetworkRequest request;
        //DC request.setUrl(QUrl("http://download.qt.io/official_releases/qt/5.13/5.13.1/qt-opensource-mac-x64-5.13.1.dmg"));
        request.setUrl(QUrl(URL));
        QNetworkReply *reply = mgr.head(request);
        connect(reply, SIGNAL(finished()), this, SLOT(onLoadFinished()));
        state = StateCheck;
    }
    else if (state == StateCheck)
    {
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        //qDebug() << reply->attribute(QNetworkRequest::ResourceTypeAttribute).toUrl();

        //分段請求
        QNetworkRequest request;
        request.setUrl(URL);

        int sectionOne = fileSize / 4;
        QString strSectionOne = QString::number(sectionOne);
        QString sectionOneRange = QString("bytes=0-%1").arg(strSectionOne);
        request.setRawHeader("Range", sectionOneRange.toUtf8());

        qDebug() << "request range: " << sectionOneRange;

        QNetworkReply *reply = mgr.head(request);
        connect(reply, SIGNAL(finished()), this, SLOT(onLoadFinished()));
        connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));

        state = StateDownload;

        reply->deleteLater();
    }
    else if (state == StateDownload)
    {
        qDebug() << "finished.";
    }
}

void HttpDownloadResume::onDownloadProgress(qint64 cur, qint64 total)
{
    qDebug() << "down: " << cur << "/" << total;
}
