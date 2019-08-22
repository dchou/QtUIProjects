#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QDateTime>

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
        //創建文件對象
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

        //-----------------------
        //獲取文件信息
        QFileInfo info(path);
        qDebug() << "文件名稱: " << info.fileName(); // info.filename().toUtf8().data();
        qDebug() << "文件後綴: " << info.suffix();
        qDebug() << "文件大小: " << info.size();
        qDebug() << "文件創建時間: " << info.created().toString("yyyy-MM-dd hh:mm:ss"); //2016-01-14 15:13:00
    }
}

void Widget::on_buttonWrite_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt)");
    if (path.isEmpty() == false)
    {
        //創建文件對象
        //OK QFile file(path);
        QFile file;
        file.setFileName(path);

        //打開文件 只寫方式
        bool isOK = file.open(QIODevice::WriteOnly);
        if (isOK == true)
        {
            //讀文件, 默認只識別 UTF8 編碼
            QString str = ui->textEdit->toPlainText();
            //寫文件
            //1. QString -> QByteArray
            //OK file.write(str.toUtf8());

            //2. QString -> C++ string -> char *
            file.write(str.toStdString().data());  //OK
            //或
            file.write(str.toLocal8Bit());         //轉換為本地頻台編碼

            //QString -> QByteArray
            QString str1 = "123";
            QByteArray a = str1.toUtf8();  //中文
            a = str1.toLocal8Bit();        //本地編碼

            //QByteArray -> char *
            char *b = a.data();

            //char * -> QString
            char *p = "abc";
            QString str3 = QString(p);
        }

        //關閉文件
        file.close();
    }
}
