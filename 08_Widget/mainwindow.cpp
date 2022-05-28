#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //栈控件的使用
    //ScrollArea 按钮
    connect(ui->btn_scrollArea,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    //toolBox按钮
    connect(ui->btn_ToolBox,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    //tabWidget按钮
    connect(ui->btn_TabWidget,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("兰博基尼");

    connect(ui->pushButton_6,&QPushButton::clicked,this,[=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("兰博基尼");
    });

    //利用QLable显示资源 可以显示动图
    ui->label->setPixmap(QPixmap(":/image/la.jpg"));
    //可以显示动图
    //QMovie *movie=new QMovie();
    //ui->label->setMovie(movie);
    //movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
