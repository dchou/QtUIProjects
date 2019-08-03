#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

public slots:  // <--- 使用Qt4信號連接方式: Qt4槽函數必須有 slots 關鍵字來修飾
    void mySlot();
    void changeWin();
    void dealSub();
    void dealSlot(int, QString);

private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;

    SubWidget subWin;
};

#endif // MAINWIDGET_H
