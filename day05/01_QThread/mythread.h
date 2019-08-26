#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

//NG class MyThread : public QObject
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

protected:
    //QThread 的虛函數
    //線程處理函數
    //不能直接調用，通過start()間接調用
    void run();

signals:
    void isDone();

public slots:
};

#endif // MYTHREAD_H
