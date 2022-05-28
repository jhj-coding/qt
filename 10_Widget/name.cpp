#include "name.h"
#include <QDebug>
#include <QMouseEvent>
#include <QLabel>
name::name(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪 只要鼠标一移动就触发不用鼠标点击着移动
    setMouseTracking(true);
}
void name::enterEvent(QEvent *event){
    qDebug()<<"鼠标进入了";
}
void name::leaveEvent(QEvent *event){
    qDebug()<<"鼠标离开了";
}
void name::mouseMoveEvent(QMouseEvent *ev){
    //鼠标点击着移动
    //移动的判断和点击不一样
//    if(ev->buttons()&Qt::LeftButton){
//    qDebug()<<"鼠标移动了";
//    }
    qDebug()<<"鼠标移动了";
}
void name::mousePressEvent(QMouseEvent *ev){
    if(ev->button()==Qt::LeftButton){
    QString str=QString("鼠标点击了 x=%1  y=%2 ").arg(ev->x()).arg(ev->y());
    qDebug()<<str;}
}
void name::mouseReleaseEvent(QMouseEvent *ev){
    qDebug()<<"鼠标松开了";
}
bool name::event(QEvent *e){
    //如果是鼠标按下，在event 事件分发来拦截
    if(e->type()==QEvent::MouseButtonPress){
        //类型转换
        QMouseEvent * ev= static_cast<QMouseEvent *>(e);
        QString str=QString("鼠标点击了 x=%1  y=%2 ").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
        //true 表示用户自己处理这个事件，不向下分发
        return true;
    }
    //其他事件交给父类处理
    return QLabel::event(e);
}
