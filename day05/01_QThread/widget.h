#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>  //定時器頭文件

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *myTimer; //聲明變量
};

#endif // WIDGET_H
