#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QPushButton>
#include <QMessageBox>
#include <QEvent>

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

    //安裝過濾器
    ui->label_2->installEventFilter(this);
    ui->label_2->setMouseTracking(true);
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

bool MyWidget::event(QEvent *e)
{
    //事件分发
    /*switch(e->type())
    {
        case QEvent::Close: {
            QCloseEvent *closeEv = static_cast<QCloseEvent *>(e);
            closeEvent(closeEv);
            break;
        }
        case QEvent::MouseMove: {
            QMouseEvent *mouseEv = static_cast<QMouseEvent *>(e);
            mouseReleaseEvent(mouseEv);
            break;
        }
    }*/

    if (e->type() == QEvent::Timer)
    {
        //幹掉定時器
        //如果返回 true, 事件停止傳播
        QTimerEvent *timerEv = static_cast<QTimerEvent *>(e);
        timerEvent(timerEv);
        return true;
    }
    else if (e->type() == QEvent::KeyPress) {
        QKeyEvent *keyEv = static_cast<QKeyEvent *>(e);
        if (keyEv->key() == Qt::Key_B)
        {
            return QWidget::event(e);
        }
        return true;
    }
    else {
        return QWidget::event(e);
    }
}

bool MyWidget::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == ui->label_2)
    {
        //判斷事件
        if (e->type() == QEvent::MouseMove)
        {
            QMouseEvent *env = static_cast<QMouseEvent *>(e);
            ui->label_2->setText(QString("Mouse move:(%1, %2)").arg(env->x()).arg(env->y()));
            return true; //不再傳遞
        }
    }
    if (obj == ui->pushButton)
    {
        //...
    }
    return QWidget::eventFilter(obj, e);
}
