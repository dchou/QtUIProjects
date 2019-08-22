#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../", "TXT(*.txt)");
    if (path.isEmpty() == false)
    {
        //文件對象
        QFile file(path);

        //打開文件 只讀方式
        bool isOK = file.open(QIODevice::ReadOnly);
        if (isOK == true)
        {
#if 0
            //讀文件, 默認只識別 UTF8 編碼
            QByteArray array = file.readAll();
            //OK ui->textEdit->setText(QString(array));
            ui->textEdit->setText(array);  //OK
#endif
            QByteArray array;
            while (file.atEnd() == false)
            {
                //讀一行
                array +=file.readLine();
            }
            ui->textEdit->setText(array);
        }

        //關閉文件
        file.close();
    }
}
