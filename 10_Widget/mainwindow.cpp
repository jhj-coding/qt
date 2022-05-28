#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //启动定时器 单位毫秒
   id1=startTimer(1000);
   id2=startTimer(2000);
   //定时器第二种方式
   QTimer * timer=new QTimer(this);
   timer->start(500);
   connect(timer,&QTimer::timeout,this,[=](){
       static int num=1;
       ui->label_4->setText(QString::number(num++));
   });
   //点击暂停
   connect(ui->pushButton,&QPushButton::clicked,this,[=](){
       timer->stop();
   });

   //安装事件过滤器
   ui->label->installEventFilter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timerEvent(QTimerEvent *event){
    if(event->timerId()==id1){
    static int num=1;
    ui->label_2->setText(QString::number(num++));
    }else if(event->timerId()==id2){
        static int num2=1;
        ui->label_3->setText(QString::number(num2++));
        }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event){
    if(watched==ui->label){
        if(event->type()==QEvent::MouseButtonPress){
            return true;
        }
    }
    return QWidget::eventFilter(watched,event);
}
