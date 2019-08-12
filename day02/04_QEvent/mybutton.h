#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include "QPushButton"

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);

protected:
    //鼠標點擊事件
    void mousePressEvent(QMouseEvent *ev);

signals:

public slots:
};

#endif // MYBUTTON_H
