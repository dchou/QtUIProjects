#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    //方法ㄧ：
    //  QPainter p(this);

    //方法二：
    //  QPainter p;  //創建畫家對象
    //  p.begin(this); //指定當前窗口為繪圖設備
    //
    //  //繪圖操作
    //  p.drawxxx();
    //  p.end();

    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap("://Image/sunny.png"));

    //OK
    //QPainter p;  //創建畫家對象
    //p.begin(this); //指定當前窗口為繪圖設備
    //p.drawPixmap(0, 0, width(), height(), QPixmap("://Image/Sunny.jpg"));
    //p.end();
}
