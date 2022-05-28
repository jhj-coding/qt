#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <mythread.h>
#include <QThread>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
signals:
    void stratThread();//启动子线程的信号
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    MyThread *myT;
    QThread *thread;
};

#endif // WIDGET_H
