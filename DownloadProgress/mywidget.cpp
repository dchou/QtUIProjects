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
}

void MyWidget::on_pushButton_clicked()
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager();

    QNetworkRequest request;
    request.setUrl(QUrl(URL));

    QNetworkReply *reply = mgr->get(request);  //自动产生新的線程

    connect(reply, SIGNAL(finished()), this, SLOT(onDownloadFinished()));
    connect(reply, SIGNAL(downloadProgress(qint64 bytesReceived, qint64 bytesTotal)),
                          this, SLOT(onDownloadProgress(qint64, qint64)));

    qDebug() << "start download image:";
}

void MyWidget::onDownloadFinished()
{

}

void MyWidget::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    qDebug() << bytesReceived;
}
