#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    timer->start(500);
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        //手动调用绘图事件
        x+=20;
        update();
    });
    connect(timer,&QTimer::timeout,this,[=](){
        //手动调用绘图事件
        x+=20;
        update();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *){
    //实例化画家
//    QPainter *painter=new QPainter(this);
//    //设置画笔
//    QPen *pen=new QPen(QColor(0,255,0));
//    pen->setWidth(3);
//    pen->setStyle(Qt::DotLine);
//    painter->setPen(*pen);
//    //设置画刷
//    QBrush *brush=new QBrush(QColor(0,0,255));
//    brush->setStyle(Qt::Dense7Pattern);
//    painter->setBrush(*brush);
//    //线
//    painter->drawLine(QPoint(0,0),QPoint(100,100));
//    //圆
//    painter->drawEllipse(QPoint(100,100),50,50);
//    //矩形
//    painter->drawRect(QRect(QPoint(100,100),QPoint(200,200)));
//    //字
//    painter->drawText(QRect(10,200,100,50),"好好学习");
    //高级设置
//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //设置抗锯齿效率比较低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

//    painter.drawRect(QRect(20,20,50,50));
//    //让画家移动100
//    painter.translate(100,0);

//    //保存画家状态
//    painter.save();
//    painter.drawRect(QRect(20,20,50,50));
//    //还原画家的状态
//    painter.restore();
//    painter.drawRect(QRect(20,20,50,50));
    //利用画家 画资源文件
        QPainter painter(this);
        painter.drawPixmap(x,20,100,100,QPixmap(":/image/la.jpg"));
        //超过屏幕宽度就返回
        if(x>this->width()){
            x=0;
        }

}
