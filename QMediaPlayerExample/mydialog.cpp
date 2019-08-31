// https://www.youtube.com/watch?v=tGKmQy-VBX0
// QT       += core gui multimedia multimediawidgets

#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}
