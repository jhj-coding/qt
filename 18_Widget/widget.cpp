#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    thread=new Mythread();
    connect(timer,&QTimer::timeout,this,[=](){
       static int i=0;
       i++;
       //设置lcd的值
       ui->lcdNumber->display(i);
    });
    connect(thread,&Mythread::isDone,this,[=](){
        qDebug()<<"执行结束";
        timer->stop();
    });
    //点击窗口关闭时
    connect(this,&Widget::destroyed,this,[=](){
        //停止线程
        thread->quit();
        //等待线程处理完毕
        thread->wait();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(timer->isActive()==false){
        timer->start(100);
    }
   thread->start();
}
