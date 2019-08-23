#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>       //內存文件
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QBuffer memFile; //創建內存文件
    memFile.open(QIODevice::WriteOnly);

    memFile.write("1111111111\n");
    memFile.write("22222222222222");

    memFile.close();
    qDebug() << "QBuffer: " << memFile.buffer();

    //----------------------------------------
    QByteArray array;
    //QBuffer(QByteArray * byteArray, QObject * parent = 0)
    QBuffer memFile1(&array);

    memFile1.open(QIODevice::WriteOnly);

    memFile1.write("33333333");
    memFile1.write("4444444444444444");
    memFile1.close();

    qDebug() << "QBuffer: " << memFile1.buffer();
    qDebug() << "QByteArray: " << array;

    //----------------------------------------
    QBuffer memFile2;
    memFile2.open(QIODevice::WriteOnly);
    QDataStream stream(&memFile2);
    stream << QString("測試") << 250;
    memFile2.close();

    qDebug() << "QBuffer: " << memFile2.buffer(); // (1).
    //(1). 這樣子無法取出 "測試" & 250

    memFile2.open(QIODevice::ReadOnly);
    QDataStream in;
    in.setDevice(&memFile2);
    QString str;
    int a;
    in >> str >> a;                               // (2).
    //(2). 這樣子可以取出 "測試" & 250
    memFile2.close();

    qDebug() << str.toUtf8().data() << a;
}

Widget::~Widget()
{
    delete ui;
}
