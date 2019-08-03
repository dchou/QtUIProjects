#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;    //執行 MainWidget 的構造函數
    w.show();

    return a.exec();
}
