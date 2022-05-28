#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class Mythread : public QThread
{
    Q_OBJECT
public:
    explicit Mythread(QThread *parent = nullptr);
protected:
    //QThread的虚函数
    //线程处理函数
    //不能直接调用需要通过start（）间接调用
    void run();
signals:
    void isDone();
public slots:
};

#endif // MYTHREAD_H
