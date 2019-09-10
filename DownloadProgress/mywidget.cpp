// reference: https://www.cnblogs.com/li-peng/p/3656613.html
#include "mywidget.h"
#include "ui_mywidget.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFileInfo>
#include <QDir>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
    ui->progressBar->setMinimum(0);    //設置最小值
    ui->progressBar->setValue(0);      //設置當前值
    ui->progressBar->setMinimum(100);  //設置最大值
}

void MyWidget::on_pushButton_clicked()
{
    QNetworkRequest request;
    request.setUrl(QUrl(URL));

    mgr = new QNetworkAccessManager(this);
    reply = mgr->get(request);  //自动产生新的線程

    bool rc1 = connect(reply, SIGNAL(finished()), this, SLOT(onDownloadFinished()));
    qDebug() << "rc1: " << rc1;
    bool rc2 = connect(reply, SIGNAL(downloadProgress(qint64, qint64)),
                          this, SLOT(onDownloadProgress(qint64, qint64)));
    qDebug() << "rc2: " << rc2;
    bool rc3 = connect(reply,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    qDebug() << "rc3: " << rc3;

    qDebug() << "start download image:";
}

void MyWidget::onDownloadFinished()
{
    qDebug() << "onDownloadFinished()";
    file->flush();
    file->close();
}

void MyWidget::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    int percent = float(bytesReceived) / float(bytesTotal) * 100;
    qDebug() << "onDownloadProgress() " << percent;
    ui->progressBar->setValue(percent);
}

void MyWidget::onReadyRead()
{
    qDebug() << "onReadyRead() ";

    QFileInfo fileinfo(reply->url().path());
    QString thefileName = fileinfo.fileName().isEmpty()?"index.html":fileinfo.fileName();

    QString thePath = "/tmp/download/";
    //qDebug()<<thePath;
    QDir createfile;
    bool exist = createfile.exists(thePath);
    if(!exist)
    {
        createfile.mkpath(thePath);
    }
    thePath += thefileName;
    qDebug() << "onReadyRead(): " << thePath;
    file = new QFile(thePath);

//    if(file->open(QIODevice::Append))
//    {
//        file->write(managerReply->readAll());
//        file->flush();
//        file->close();
//    }
    if(file->open(QIODevice::Append))
    {
        file->write(reply->readAll());
        file->flush();
    }
    //delete file;
}
