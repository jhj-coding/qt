#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)//初始化列表
{
    //创建一个按钮
    QPushButton *btn=new QPushButton;
    //btn.show();//show以顶层的方式弹出窗口
    //让btn对象出现在mywidget窗口中
    btn->setParent(this);
    //设置文本
    btn->setText("第一个按钮");
    //设置控件大小
    //btn->resize(50,50);
    //创建第二个按钮，按照控件大小创建窗口
    QPushButton *btn1=new QPushButton("第二个按钮",this);
    //两个按钮会在一块所以要移动
    btn1->move(100,0);
    //重置窗口大小
    resize(600,400);
    //设置固定窗口大小不可以移动
    setFixedSize(600,400);
    //设置窗口标题
    setWindowTitle("第一个窗口");
     MyPushButton *myBtn=new MyPushButton();
     myBtn->setText("1");
     myBtn->move(100,100);
     myBtn->setParent(this);
     connect(myBtn,&QPushButton::clicked,this,&myWidget::close);
}

myWidget::~myWidget()
{
    qDebug()<<"myWidget的析构调用";
}
