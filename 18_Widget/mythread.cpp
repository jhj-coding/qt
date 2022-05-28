#include "mythread.h"

Mythread::Mythread(QThread *parent) : QThread(parent)
{

}
void Mythread::run(){
    //很复杂的下数据处理需要耗时
    sleep(5);
    emit isDone();
}
