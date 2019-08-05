#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>

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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_change_clicked()
{

}
