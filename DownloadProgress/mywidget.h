#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_pushButton_clicked();
    void onDownloadFinished();
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void onReadyRead();

private:
    //QString URL = "http://cdn.atgamescloud.com/retro-apps/production/AppVersion/ha8800_test/10/ha8800_0.9.100.img?ttl=1568108934&sig=b5a5bfe3d5ad62305bba9ce531695742";
    QString URL = "https://mirrors.tuna.tsinghua.edu.cn/qt/archive/online_installers/3.1/qt-unified-mac-x64-3.1.1-online.dmg";
    Ui::MyWidget *ui;
    QNetworkAccessManager *mgr;
    QNetworkReply *reply;
    QFile *file;
};

#endif // MYWIDGET_H
