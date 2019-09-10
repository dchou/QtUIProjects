#include "mywidget.h"
#include "ui_mywidget.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

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

    QNetworkReply *reply = mgr.get(request);  //自动产生新的線程

    bool rc1 = connect(reply, SIGNAL(finished()), this, SLOT(onDownloadFinished()));
    qDebug() << "rc1: " << rc1;
    bool rc2 = connect(reply, SIGNAL(downloadProgress(qint64, qint64)),
                          this, SLOT(onDownloadProgress(qint64, qint64)));
    qDebug() << "rc2: " << rc2;
    qDebug() << "start download image:";
}

void MyWidget::onDownloadFinished()
{
    qDebug() << "onDownloadFinished()";
}

void MyWidget::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    float percent_float = float(bytesReceived) / float(bytesTotal);
    int precent_int = percent_float * 100;
    qDebug() << "onDownloadProgress() " << percent_float;
    ui->progressBar->setValue(precent_int);

}
