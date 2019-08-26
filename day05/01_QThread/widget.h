#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>  //定時器頭文件
#include "mythread.h"  //線程頭文件

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void dealTimeout(); //定时器槽函数
    void dealDone(); //線程結束槽函數
    void stopThread(); //停止線程槽函數

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *myTimer; //聲明變量
    MyThread *thread; //線程對象
};

#endif // WIDGET_H
