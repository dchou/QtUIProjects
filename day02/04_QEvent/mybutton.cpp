#include "mybutton.h"
#include "QPushButton"
#include <QMouseEvent>
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        qDebug() << "按下的是左鍵";

        ev->ignore(); //我要忽略這個事件。事件繼續往下傳遞，但是傳遞給誰？
                      //事件傳遞給了父組件，不是給父類(基類)
                      //本例中，父組件是 MyWidget
    }
    else
    {
        //不做處理
        QPushButton::mousePressEvent(ev); //預設就是這樣
    }
}
