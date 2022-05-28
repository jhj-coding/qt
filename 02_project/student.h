#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //早期QT版本 必须要写到public slots,高级版本可以写到public下或者全局下
    //返回值void 需要声明也需要实现
    //可以有参数，可以发生重载
    void treat();
    void treat(QString foodName);
};

#endif // STUDENT_H
