#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //tableWidget 控件
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    ui->tableWidget->setRowCount(5);
    QStringList nameList=QStringList()<<"亚瑟"<<"1"<<"2"<<"3"<<"4";
    QStringList sex=QStringList()<<"亚瑟"<<"1"<<"2"<<"3"<<"4";
    //设置正文
    for(int i=0;i<5;i++){
        int col=0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sex.at(i)));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
