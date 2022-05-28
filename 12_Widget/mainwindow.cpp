#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <QPainter>
#include <QBrush>
#include <QPicture>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    //绘图设备
//    QPixmap pix(300,300);
//    //设置设备的背景
//    pix.fill(Qt::white);
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(50,50),50,50);
//    //保存
//    pix.save("E://1.jpg");

//    //可以对每一个像素进行访问
//    QImage image(300,300,QImage::Format_RGB666);
//    image.fill(Qt::white);
//    QPainter painter(&image);
//    painter.drawEllipse(QPoint(50,50),50,50);
//    image.save("E:/1.jpg");
    //QPicture 绘图设备 可以记录和重新绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setBrush(QBrush(QColor(Qt::blue)));
    painter.drawEllipse(QPoint(50,50),50,50);
    painter.end();
    pic.save("E:/pic.zt");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event){
    //利用Qimage对像素进行修改
    QPainter painter(this);
//    QImage img;
//    img.load(":/image/la.jpg");
//    for(int i=50;i<100;i++){
//        for(int j=50;j<100;j++){
//            img.setPixel(QPoint(i,j),qRgb(255,0,0));
//        }
//    }
//    painter.drawImage(0,0,img);

    //重现QPicture 的绘图指令
    QPicture pic;
    pic.load("E:/pic.zt");
    painter.drawPicture(0,0,pic);
}
