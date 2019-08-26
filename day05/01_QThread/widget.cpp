#include "widget.h"
#include "ui_widget.h"
#include "widget.h"
#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myTimer = new QTimer(this);

    //只要定時器啟動 自動觸發 timeout
    connect(myTimer, &QTimer::timeout, this, &Widget::dealTimeout);
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

void Widget::on_pushButton_clicked()
{
    //如果定時器沒有工作
    if (myTimer->isActive() == false)
    {
        myTimer->start(100); // 100 msec
    }

    //模擬很复杂的数据处理 需要耗时5s
    QThread::sleep(5);  //图形界面中一旦使用了线程休眠，图形界面就不会刷新(不会动)，呈现卡住无响应的状态。
    //也就是说由于睡眠，导致前面启动了的定时器都不工作

    myTimer->stop();//过了5s后图形界面才会有响应。但是
    //此时是停了定时器，前面是睡眠 定时器也不工作，所以呈现出一直定时器一直不工作的状态

    qDebug() << "over";
}
