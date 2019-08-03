#include <QApplication>
#include <QWidget> // 窗口控件基類
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    w.setWindowTitle("主要看氣質");

    /*如果不指定父對象，對象和對象(窗口和窗口) 沒有關係，獨立
     * a 指定 b 為他的父對象，a 放在 b 的上面
     * 指定父對象，有兩種方式：
     *    1) setParent()
     *    2) 通過構造函數傳參
     * 指定父對象，只需要父對象顯示，上面的子對象會自動顯示
     */
    QPushButton b;
    b.setParent(&w);   //指定父對象
    b.setText("^_^");
    b.move(100,100);
    //b.show();

    QPushButton b1(&w); //通過構造函數傳參，指定父對象
    b1.setText("abc");

    w.show();
    app.exec();
    return 0;
}
