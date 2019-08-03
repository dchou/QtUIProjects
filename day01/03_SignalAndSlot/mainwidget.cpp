#include "mainwidget.h"
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2 = new QPushButton(this); // b2 是指針, 所以要動態 new
    b2->setText("abc");

    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);
    /* &b1: 信號發出者，指針類型
     * &QPushButton::pressed: 處理的信號，       &發送者的類名::信號名字
     * this: 信號接收者
     * &MainWidget::close: 槽函數，信號處理函數   &接收者的類名::槽函數名字
     */

    /* 自定義槽
     * Qt5: 任意的成員函數，普通全局函數，靜態函數
     * 槽函數需要和信號一致（參數，返回值）
     * 由於信號都是沒有返回值，所以，槽函數一定沒有返回值
     */
    connect(b2, &QPushButton::released, this, &MainWidget::mySlot);
    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);

    /* 信號：現實生活的短信
     * 槽函數：接收短信的手機
     */

    setWindowTitle("老大");  // 相同於 this->setWindowTitle("老大");

    b3.setParent(this);
    b3.setText("切換到子窗口");
    b3.move(50,50);

    //顯示子窗口
    //w.show();
    connect(&b3, &QPushButton::released, this, &MainWidget::changeWin);

    //處理子窗口的信號
    connect(&w, &SubWidget::mySignal, this, &MainWidget::dealSub);
    resize(400, 300);
}

void MainWidget::mySlot()
{
    b2->setText("123");
}

void MainWidget::changeWin()
{
    //子窗口顯示
    w.show();
    //本窗口隱藏
    this->hide();
}

void MainWidget::dealSub()
{
    //子窗口隱藏
    w.hide();
    //本窗口顯示
    this->show();
}

MainWidget::~MainWidget()
{

}
