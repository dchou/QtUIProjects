#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPicture picture;
    QPainter p;
    p.begin(&picture);

    p.drawPixmap(0, 0, 80, 80, QPixmap("../Image/butterfly.png"));
    p.drawLine(50, 50, 150, 50);

    p.end();

    //保存的是二進制文件
    picture.save("../picture.bin"); // in binary format, not png format
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
#if 0
    QPicture pic;
    pic.load("../picture.bin");

    QPainter p(this);
    p.drawPicture(0, 0, pic);
#endif

    QPainter p(this);
    QPixmap pixmap;
    pixmap.load("../Image/butterfly.png");

    //QPixmap -> QImage
    QImage tempImage = pixmap.toImage();
    p.drawImage(0, 0, tempImage);

    //-------------------------
    QImage image;
    image.load("../Image/butterfly.png");

    //QImage -> QPixmap
    QPixmap tempPixmap = QPixmap::fromImage(image);
    p.drawPixmap(150, 0, tempPixmap);
}
