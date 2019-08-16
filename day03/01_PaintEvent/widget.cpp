#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

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

    //OK QPainter p(this);
    //OK p.drawPixmap(0, 0, width(), height(), QPixmap("://Image/sunny.png"));
    //OK p.drawPixmap(rect(), QPixmap("://Image/sunny.png"));

    //OK
    //QPainter p;  //創建畫家對象
    //p.begin(this); //指定當前窗口為繪圖設備
    //p.drawPixmap(0, 0, width(), height(), QPixmap("://Image/Sunny.jpg"));
    //p.end();

    QPainter p;    //創建畫家對象
    p.begin(this);

    //定義畫筆
    QPen pen;
    pen.setWidth(5);
    //OK pen.setColor(Qt::red);      //設置顏色
    pen.setColor(QColor(14, 9, 234)); //rgb設置顏色
    pen.setStyle(Qt::DashLine);      //設置風格

    //把畫筆交給畫家
    p.setPen(pen);

    //畫直線
    p.drawLine(50, 50, 150, 50);
    p.drawLine(50, 50, 50, 150);

    //創建畫刷對象
    QBrush brush;
    brush.setColor(Qt::red);      //設置顏色
    brush.setStyle(Qt::Dense1Pattern);

    //把畫刷交給畫家
    p.setBrush(brush);

    //畫矩形
    p.drawRect(150, 150, 100, 50);

    //畫圓形/橢圓形
    p.drawEllipse(QPoint(150, 150), 50, 25);

    //畫笑臉
    p.drawPixmap(x, 180, 80, 80, QPixmap("://Image/OnePiece.png"));

    p.end();
}


void Widget::on_pushButton_clicked()
{
    x += 20;
    if (x>width())
    {
        x = 0;
    }

    //刷新窗口，讓窗口重繪
    update();  //間接調用 paintEvent()
}
