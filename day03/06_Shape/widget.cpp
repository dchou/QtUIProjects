#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //去窗口邊框
    //NG setWindowFlag(Qt::FramelessWindowHint | windowFlags() );
    int flags = windowFlags();                 //DC
    flags |= Qt::FramelessWindowHint;          //DC
    setWindowFlag((Qt::WindowType) flags);     //DC

    //把窗口背景設置為透明
    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
    //設置追蹤鼠標
    this->setMouseTracking(true);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    //注意: 必須是透明背景的 png 才能有不規則的效果
    p.drawPixmap(0, 0, QPixmap("../Image/sunny.png"));
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton)
    {
        //如果是右鍵
        close();
    }
    else if (e->button() == Qt::LeftButton)
    {
        //求座標差値
        //當前點擊座標 - 窗口左上角座標
        p = e->globalPos() - this->frameGeometry().topLeft();
        qDebug() << p;
    }
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    //qDebug() << "mouseMoveEvent(): " << e->button();
    if (e->button() & Qt::LeftButton)
    {
        //qDebug() << "   in the loop";
        move(e->globalPos() - p);
        //qDebug() << e->globalPos() - p;
    }
}
