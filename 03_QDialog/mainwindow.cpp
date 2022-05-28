#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击新建按钮弹出一个对话框
    connect(ui->actionnew,&QAction::triggered,this,[=](){
        //对话框 分类
        //模态对话框（不可以对其他窗口进行操作） 非模态对话框（可以对其他窗口进行操作）
        //模态创建 阻塞 的功能 即对话框不点关闭就不会执行后续代码
        //QDialog *dlg=new QDialog(this);
        //dlg->resize(200,100);
       // dlg->exec();
        //qDebug()<<"模态框弹出来";

        //非模态对话框
//        QDialog *dlg2= new QDialog(this);//防止不会一闪而过
//        dlg2->show();
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);//防止内存爆，关闭时释放掉
//        dlg2->resize(200,100);
//        qDebug()<<"非模态框弹出来";

        //消息对话框  模态
        //错误对话框
        //QMessageBox::critical(this,"critical","错误");
        //信息对话框
        //QMessageBox::information(this,"1","2");
        //提问对话框
        //参数1 父亲 参数2 标题 参数3 提示内容 参数4 按键类型 参数5 默认关联回车的按键
        //QMessageBox::question(this,"1","2",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel);
        //进行按键点击判断
//        if(QMessageBox::Save==QMessageBox::question(this,"1","2",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel)){
//            qDebug()<<"保存";
//        }else{
//            qDebug()<<"取消";
//        }
        //警告对话框
//        QMessageBox::warning(this,"warning","警告");


    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
