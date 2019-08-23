#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData()
{
    //創建文件對象
    QFile file("../test.txt");

    //打開文件, 只寫方式打開
    bool isOk = file.open(QIODevice::WriteOnly);
    if (true == isOk)
    {
        //创建数据流，和file文件关联
        //往数据流中写数据，相当于往文件里写数据
        QDataStream stream(&file);

        stream << QString("主要看气质") << 250;

        file.close();

    }
}

void Widget::readData()
{
    //創建文件對象
    QFile file("../test.txt");

    //打開文件, 只讀方式打開
    bool isOk = file.open(QIODevice::ReadOnly);
    if (true == isOk)
    {
        //创建数据流，和file文件关联
        //往数据流中讀数据，相当于從文件里讀数据
        QDataStream stream(&file);

        //讀的時候, 按寫的次序取數據
        QString str;
        int a;
        stream >>  str >> a;
        cout << str.toUtf8().data() << a;
        file.close();

    }
}
