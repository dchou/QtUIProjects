#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

protected:
    //鍵盤按下事件
    void keyPressEvent(QKeyEvent *);
    //計時器事件
    void timerEvent(QTimerEvent *);

private:
    Ui::MyWidget *ui;

    int timerId;
};

#endif // MYWIDGET_H
