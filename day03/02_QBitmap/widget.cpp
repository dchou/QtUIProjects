#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << QDir::currentPath();
    //輸出 "/Code/Qt/QtUIProjects/day03/build-02_QBitmap-Desktop_Qt_5_9_8_clang_64bit-Debug/02_QBitmap.app/Contents/MacOS"
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    //QPixmap 圖片背景透明
    p.drawPixmap(0, 0, QPixmap("../../../../Image/butterfly.png"));
    //QBitmap 圖片背景透明
    p.drawPixmap(200, 0, QBitmap("../../../../Image/butterfly.png"));

    //QPixmap 圖片背景白色
    QPixmap pixmap;
    pixmap.load("../../../../Image/butterfly1.png");
    p.drawPixmap(0, 200, pixmap);
    //QBitmap 圖片背景白色
    QBitmap bitmap;
    bitmap.load("../../../../Image/butterfly1.png");
    p.drawPixmap(200, 200, bitmap);
}
