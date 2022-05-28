#include "student.h"
#include <QDeBug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat(){
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName){
    qDebug()<<"请老师吃"+foodName;
}
