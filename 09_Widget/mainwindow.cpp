#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        qDebug()<<ui->widget->getNum();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        ui->widget->setNum(ui->widget->getNum()/2);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
