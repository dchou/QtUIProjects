#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("123");
    
    //connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::close);

    //QLineEdit
    QString str = ui->lineEdit->text();
    qDebug() << str;

    //設置內容
    ui->lineEdit->setText("abcdefg");

    //設置內容顯示間隙
    ui->lineEdit->setTextMargins(15,0,0,0); //離 left margin 15 pixels

    //設置內容顯示方式
    ui->lineEdit->setEchoMode(QLineEdit::Normal);

    QStringList list;
    list << "hello" << "How are you?" << "He he";

    QCompleter *com = new QCompleter(list, this);
    com->setCaseSensitivity(Qt::CaseInsensitive);

    ui->lineEdit->setCompleter(com);

    //QLabel
    ui->labelText->setText("xyz");

    //設置圖片
    ui->labelImage->setPixmap(QPixmap("://Image/LuffyQ.png"));
    //                                 ~~~~~~~~~~~~~~~~~~~      <--- 從 clipboard 貼上的
    //讓圖片自動適應 label 大小
    ui->labelImage->setScaledContents(true);

    //創建動畫
    QMovie *myMovie = new QMovie("://Image/mario.gif");
    //設置動畫
    ui->labelGif->setMovie(myMovie);
    //啟動動畫
    myMovie->start();
    ui->labelGif->setScaledContents(true);

    //設置 html
    ui->labelUrl->setText("<h1><a href=\"htts://www.baidu.com\">百度一下</a></h1>");
    ui->labelUrl->setOpenExternalLinks(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_change_clicked()
{

}
