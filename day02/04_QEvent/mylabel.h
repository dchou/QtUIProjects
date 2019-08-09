#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
    //鼠標點擊事件
    void mousePressEvent(QMouseEvent *ev);
    //鼠標釋放事件
    void mouseReleaseEvent(QMouseEvent *ev);
    //鼠標移動事件
    void mouseMoveEvent(QMouseEvent *ev);
    //進入窗口事件
    void enterEvent(QEvent *);
    //離開窗口事件
    void leaveEvent(QEvent *);
signals:

public slots:
};

#endif // MYLABEL_H
