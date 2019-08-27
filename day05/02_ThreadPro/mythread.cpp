#include "mythread.h"
#include <QThread>
#include <QDebug>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}

void MyThread::myTimeout()
{
    while( !isStop )
    {
        QThread::sleep(1);
        emit mySignal();

        //子線程不能處理 UI
        //QMessageBox::aboutQt(NULL);

        qDebug() << "子线程号：" << QThread::currentThread();

        /*DC if(isStop)
        {
            break;
        }*/
    }
}

void MyThread::setFlag(bool flag)
{
    isStop = flag;
}
