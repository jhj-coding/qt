#include "mywidget.h"
#include <QApplication>//包含一个应用程序类的头文件
//命令行变量的数量 命令行变量的数组
int main(int argc, char *argv[])
{
    //a为应用程序对象，在QT中有且仅有一个
    QApplication a(argc, argv);
    //窗口对象
    myWidget w;
    w.show();
    //让应用程序对象进入消息循环
    return a.exec();
}
