#include "mywidget.h"
#include "ui_mywidget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    qDebug() << QSqlDatabase::drivers();
    //輸出: ("QSQLITE", "QODBC", "QODBC3", "QPSQL", "QPSQL7")

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("12345678");
    db.setDatabaseName("info");

    if (false == db.open())
    {
        QMessageBox::warning(this, "warning", db.lastError().text());
        return;
    }
}

MyWidget::~MyWidget()
{
    delete ui;
}
