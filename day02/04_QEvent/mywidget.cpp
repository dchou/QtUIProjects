#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QPushButton>
#include <QMessageBox>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    timerId = this->startTimer(1000); //毫秒為單位，每隔一秒觸發一次

    connect(ui->pushButton, &MyButton::clicked,
            [=]()
            {
                qDebug() << "按鈕被按下";
            });
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

void MyWidget::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "父組件也收到了";
}

void MyWidget::closeEvent(QCloseEvent *e)
{
    int ret = QMessageBox::question(this, "question", "是否需要關閉窗口？");
    if (ret == QMessageBox::Yes)
    {
        //關閉窗口
        //處理關閉窗口事件，接收事件，事件就不再往下傳遞
        e->accept();
    }
    else
    {
        //不關閉窗口
        //忽略事件，事件繼續傳遞給父組件
        e->ignore();

    }
}
