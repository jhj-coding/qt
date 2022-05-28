#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyPushButton *mpb=new MyPushButton(this);
    mpb->setText("1");
    mpb->move(100,100);
    connect(mpb,&MyPushButton::clicked,this,&Widget::close);
    this->st=new Student(this);
    this->tc=new Teacher(this);
    void(Teacher::*teacherHungry)(QString)=&Teacher::hungry;
    void(Student::*studentTreat)(QString)=&Student::treat;
    connect(tc,teacherHungry,st,studentTreat);
    classIsOver("宫保鸡丁");
    resize(300,300);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::classIsOver(){
    emit tc->hungry();
}
void Widget::classIsOver(QString foodName){
    emit tc->hungry(foodName);
}
