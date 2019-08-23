#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
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
    QFile file("../demo.txt");

    bool isOk = file.open(QIODevice::WriteOnly);
    if (true == isOk)
    {
        QTextStream stream(&file);
        //指定編碼
        stream.setCodec("UTF8"); // "GB18030"

        stream << QString("主要看气质") << 250;
    }
    file.close();
}

void Widget::readData()
{
    QFile file("../demo.txt");

    bool isOk = file.open(QIODevice::ReadOnly);
    if (true == isOk)
    {
        QTextStream stream(&file);
        //指定編碼
        stream.setCodec("UTF8");

        //讀的時候, 按寫的次序取數據
        QString str;
        int a;
        stream >> str >> a;
        cout << str << a;
        //輸出: [ ..\09_QTextStream\widget.cpp : 54 ] "主要看气质250" 0
    }
    file.close();
}
