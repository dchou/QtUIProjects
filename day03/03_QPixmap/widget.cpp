#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //繪圖設備 400x300
    QPixmap pixmap(400, 300);
    QPainter p(&pixmap);

    //填充背景色
    //OK p.fillRect(0, 0, 400, 300, QBrush(Qt::white));
    //或
    pixmap.fill(Qt::white); //OK

    p.drawPixmap(0, 0, 80, 80, QPixmap("../../../../Image/down.png"));

    //保存圖片
    pixmap.save("../../../../pixmap.png");  //OK
    //或
    //OK pixmap.save("../../../../pixmap.jpg");
}

Widget::~Widget()
{
    delete ui;
}
