#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //設置追蹤鼠標
    this->setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();

    if (ev->button() == Qt::LeftButton)
    {
        qDebug() << "left";
    } else if (ev->button() == Qt::RightButton)
    {
        qDebug() << "right";

    } else if (ev->button() == Qt::MidButton)
    {
        qDebug() << "mid";
    }

    //To format string, we use sprinf() function in C++, but use ... in Qt
    /*
     * QString str = QString("abc %1 ^_^ %2).arg(123).arg("Mike");
     * str = "abc 123 ^_^ Mike"
    */
    QString text = QString("<center><h1>Mouse Press: (%1, %2)</h1></center>")
            .arg(i).arg(j);
    this->setText(text);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Release: (%1, %2)</h1></center>")
            .arg(ev->x()).arg(ev->y());
    this->setText(text);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Move: (%1, %2)</h1></center>")
            .arg(ev->x()).arg(ev->y());
    //this->setText(text);
}

void MyLabel::enterEvent(QEvent *)
{
    QString text = QString("<center><h1>Mouse Enter</h1></center>");
    this->setText(text);
}

void MyLabel::leaveEvent(QEvent *)
{
    QString text = QString("<center><h1>Mouse Leave</h1></center>");
    this->setText(text);
}
