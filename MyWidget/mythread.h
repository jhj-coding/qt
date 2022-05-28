#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
//线程处理函数
    void myTimeOut();
     bool isStop;
signals:
    void mySignal();
public slots:
private:

};

#endif // MYTHREAD_H
