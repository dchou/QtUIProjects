#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>
#include <QDir>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << QDir::currentPath();

    //創建一個繪圖設備, QImage::Format_ARGB32 背景是透明
    QImage image(400, 300, QImage::Format_ARGB32);
    QPainter p;
    p.begin(&image);

    //繪圖
    p.drawImage(0, 0, QImage("../Image/down.png"));

    //對繪圖設備前50個像素點進行操作
    for (int i=0; i<50; i++)
    {
        for (int j=0; j<50; j++)
        {
            image.setPixel(QPoint(i, j), qRgb(0, 255, 0));
            //image.getPixel(QPoint(i,j));
        }
    }
    p.end();

    image.save("../image.png");

    //注意: 因為是畫到 QImage 上, 所以螢幕上看不到東西
}

Widget::~Widget()
{
    delete ui;
}
