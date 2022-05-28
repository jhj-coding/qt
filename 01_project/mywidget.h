#ifndef MYWIDGET_H
#define MYWIDGET_H
//命名规范
//类名 首字母大写 单词和单词之间首字母大写
//函数名 变量名称 首字母小写，单词和单词之间首字母大写
//快捷键
//注释 ctrl+/
//运行 ctrl+r
//编译 ctrl+b
//字体缩放 ctrl+滚轮
//查找 ctrl+f
//整行 ctrl+shift+↑或者↓
//帮助文档F1
//自动对齐 ctrl+i
//同名之间的.h与.cpp 快速切换

#include <QWidget> //包含头文件 窗口类

class myWidget : public QWidget //继承
{
    Q_OBJECT //宏，允许类中使用信号和槽的机制

public:
    myWidget(QWidget *parent = 0);  //构造函数
    ~myWidget();//析构函数
};

#endif // MYWIDGET_H
