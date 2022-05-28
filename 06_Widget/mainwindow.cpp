#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");
    //每一行
    QTreeWidgetItem * item=new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * item1=new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem * item2=new QTreeWidgetItem(QStringList()<<"智力");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(item);
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    //追加子节点
    QTreeWidgetItem * heroL1=new QTreeWidgetItem(QStringList()<<"刚被猪"<<"前排坦克，能在吸收伤害的同时造成客观的范围输出");
    QTreeWidgetItem * heroL2=new QTreeWidgetItem(QStringList()<<"刚被猪"<<"前排坦克，能在吸收伤害的同时造成客观的范围输出");
    item->addChild(heroL1);
    item1->addChild(heroL2);
    item2->addChild(heroL1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
