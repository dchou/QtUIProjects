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

    void mousePressEvent(QMouseEvent *);
    //關閉窗口事件
    void closeEvent(QCloseEvent *);
    //重寫 event 事件
    bool event(QEvent *);
    //事件過濾器
    bool eventFilter(QObject *obj, QEvent *e);

private:
    Ui::MyWidget *ui;

    int timerId;
};

#endif // MYWIDGET_H
