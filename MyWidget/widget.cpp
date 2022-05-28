#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //动态分配空间，不能指定父对象
    myT=new MyThread;
    //创建子线程
    thread=new QThread(this);
    //把自定义的线程加入子线程中
    myT->moveToThread(thread);
    connect(myT,&MyThread::mySignal,this,[=](){
        static int i=0;
        i++;
        ui->lcdNumber->display(i);
    });
    qDebug()<<"主线程号"<<QThread::currentThread();
    connect(this,&Widget::stratThread,myT,&MyThread::myTimeOut);
    connect(this,&Widget::destroyed,this,[=](){
        myT->isStop=true;
        thread->quit();
        thread->wait();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(thread->isRunning()==true){
        return;
    }
    //启动线程 并没有启动线程处理函数
    thread->start();
    myT->isStop=false;
    //不能直接调用线程处理函数
    //直接调用会让处理函数和主线程在一个线程
    //只能通过信号和槽的方式调用
    emit stratThread();
}

void Widget::on_pushButton_2_clicked()
{
    if(thread->isRunning()==false){
        return;
    }
    myT->isStop=true;
    thread->quit();
    thread->wait();
}
