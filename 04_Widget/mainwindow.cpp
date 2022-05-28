#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //单选按钮
    ui->radioButton->setChecked(true);
    bool ret;
    connect(ui->radioButton_2,&QRadioButton::clicked,this,[=](){
       qDebug()<<"选中女了";
    });
    //多选按钮
    ui->checkBox->setChecked(true);
    connect(ui->checkBox,&QCheckBox::stateChanged,this,[=](int state){
        qDebug()<<state;
    });
    //利用listWidget 写诗
//    QListWidgetItem *item=new QListWidgetItem("锄禾日当午");
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignCenter);
    QStringList list;
    list<<"锄禾日当午"<<"汗滴禾下锄";
    ui->listWidget->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}
