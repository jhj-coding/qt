#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
//Teacher 类
//Student 类
//下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建一个老师的对象，学生的对象
    this->zt=new Teacher(this);
    this->st=new Student(this);
    //connect(zt,&Teacher::hungry,st,&Student::treat);
    //有多个信号和槽时用函数指针
    void(Teacher::*teacherSignal)(QString)=&Teacher::hungry;
    void(Student::*studentSlot)(QString)=&Student::treat;
    connect(zt,teacherSignal,st,studentSlot);
    QPushButton *btn=new QPushButton(this);
    //connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);
    //断开信号
    //disconnect(zt,teacherSignal,st,studentSlot);
    //btn->setText("下课了");
    //resize(600,400);

    //信号连接信号
//    void(Teacher::*teacherSignal)(void)=&Teacher::hungry;
//    void(Student::*studentSlot)(void)=&Student::treat;
//    connect(zt,teacherSignal,st,studentSlot);
//    connect(btn,&QPushButton::clicked,zt,teacherSignal);

    //信号是可以连接信号
    //一个信号可以连接多个槽函数
    //多个信号可以连接同一个槽函数
    //信号和槽函数的参数一一对应
    //信号的参数个数可以多余槽函数的个数，其余的类型也要一一对应

    connect(btn,&QPushButton::clicked,this,[=](){
        emit zt->hungry("宫爆鸡丁");
    });
}

Widget::~Widget()
{
    delete ui;
}
void Widget::classIsOver(){
    emit zt->hungry("宫保鸡丁");
}
