#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::treat(){
    qDebug()<<"吃饭";
}
void Student::treat(QString foodName){
    qDebug()<<"吃饭"+foodName;
}
