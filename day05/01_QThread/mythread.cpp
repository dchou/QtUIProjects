#include "mythread.h"
#include <QThread>

//NG MyThread::MyThread(QObject *parent) : QObject(parent)
MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    //模擬很複雜的數據處理
    //需要耗時5s
    sleep(5);
    emit isDone();
}
