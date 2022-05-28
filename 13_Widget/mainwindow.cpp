#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDataStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击选取文件按钮，弹出文件对话框
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        QString s=QFileDialog::getOpenFileName(this,"打开文件","E:/");
        ui->lineEdit->setText(s);
        //编码格式
        //QTextCodec *code=QTextCodec::codecForName("gbk");
        //读文件 默认支持的格式为utf-8
        QFile file(s);
        //设置打开方式
        file.open(QIODevice::ReadOnly);
        //全读
        QByteArray array=file.readAll();
        //一行一行
        QByteArray a;
        //判断是否读到文件尾部
        while(!file.atEnd()){
            a+=file.readLine();
        }
        ui->textEdit->setText(array);
        //ui->textEdit->setText(code->toUnicode(array));
        //关闭文件
        file.close();

        //追加的方式写文件
//        file.open(QIODevice::Append);
//        file.write("111");
//        file.close();
        //文件的信息
//        QFileInfo info(s);
//        qDebug()<<info.suffix();
        //想读取哪些信息看帮助文档

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
