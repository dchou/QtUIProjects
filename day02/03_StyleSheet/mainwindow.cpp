#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel {color:red;}");
    ui->label_2->setStyleSheet("QLabel {background-color:rgb(0,0,255);}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
