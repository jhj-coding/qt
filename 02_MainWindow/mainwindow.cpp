#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->actionnew->setIcon(QIcon("F:/我的/la.jpg"));

    //使用添加Qt资源
    //1.将要使用的文件添加到当前项目中2.在项目中添加新文件QtResource File 右键open in editor 3.下方添加前缀 添加文件 4.使用“：+资源名+文件名”
    ui->actionnew->setIcon(QIcon(":/image/la.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
