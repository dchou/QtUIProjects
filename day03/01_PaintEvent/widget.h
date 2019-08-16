#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    //重寫繪圖事件，虛函數
    //如果在窗口繪圖，必須放在繪圖事件實現
    //繪圖事件內部自動調用，窗口需要重繪的時候（狀態改變）
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    int x = 0;
};

#endif // WIDGET_H
