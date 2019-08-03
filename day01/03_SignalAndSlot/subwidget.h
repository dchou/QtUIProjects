#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void sendSlot();

signals:
    /* 信號必須有 signals 關鍵字來聲明
     * 信號沒有返回值，但可以有參數4
     * 信號就是函數的聲明，只需聲明，無需定義
     * 使用：emit mySignal();
     * 信號可以重載
     */
    void mySignal();
    void mySignal(int, QString);

public slots:

private:
    QPushButton b;
};

#endif // SUBWIDGET_H
