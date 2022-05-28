#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *btn=new QPushButton(this);
    btn->setText("open");
    this->mw=new MyWidget();
    connect(btn,&QPushButton::clicked,this,[=](){
        if(btn->text()=="open"){
            this->mw->show();
            btn->setText("close");
        }
        else{
            this->mw->close();
            btn->setText("open");
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
