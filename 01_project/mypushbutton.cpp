#include "mypushbutton.h"
#include <QDebug>
MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug()<<"我的按钮类的构造函数调用";
}
MyPushButton::~MyPushButton(){
    qDebug()<<"我的按钮类的析构函数调用";
}
