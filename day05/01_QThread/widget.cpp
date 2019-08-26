#include "widget.h"
#include "ui_widget.h"
#include "widget.h"
#include <QThread>
#include <QDebug>
#include "mythread.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myTimer = new QTimer(this);

    //只要定時器啟動 自動觸發 timeout
    connect(myTimer, &QTimer::timeout, this, &Widget::dealTimeout);

    thread = new MyThread(this);

    connect(thread, &MyThread::isDone, this, &Widget::dealDone);

    //当按窗口右上角x时，窗口触发destroyed()，否则关了窗口线程还会运行
    connect(this, &Widget::destroyed, this, &Widget::stopThread);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dealTimeout()
{
    static int i = 0;
    i++;
    //设置lcd的值
    ui->lcdNumber->display(i);
}

void Widget::dealDone()
{
    qDebug() << "it is over";
    myTimer->stop();  //關閉定時器
}

void Widget::stopThread()
{
    //停止線程，不是立馬關閉，釋放線程佔用的內存，線程號等資源。和下面配合使用
    thread->quit();//類似linux中，pthread_exit()
    //等待線程處理完手頭動作
    thread->wait();//類似linux中，pthread_join , pthread_detach,

    //terminate 強制結束，很暴力，往往會導致內存問題。所以一般不用
}

void Widget::on_pushButton_clicked()
{
    //如果定時器沒有工作
    if (myTimer->isActive() == false)
    {
        myTimer->start(100); // 100 msec
    }

    //启动线程，处理数据
    thread->start();
}
