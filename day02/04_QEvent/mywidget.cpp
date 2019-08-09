#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QKeyEvent>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    timerId = this->startTimer(1000); //毫秒為單位，每隔一秒觸發一次
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << (char)e->key();
    if (e->key() == Qt::Key_A)
    {
        qDebug() << "Qt::Key_A";
    }
}

void MyWidget::timerEvent(QTimerEvent *e)
{
    if (e->timerId() == this->timerId)
    {
        static int sec = 0;

        ui->label->setText(QString("<center><h1>time out: %1</h1></center>").arg(++sec));

        if (5 == sec)
        {
            //停止計時器
            this->killTimer(this->timerId);
        }
    }

}
