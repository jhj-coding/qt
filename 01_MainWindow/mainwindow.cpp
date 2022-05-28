#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,400);
    //创建菜单栏 只能最多有一个
    QMenuBar *bar=menuBar();
    //将菜单栏放入到窗口中
    setMenuBar(bar);
    //创建菜单
    QMenu * fileMenu=bar->addMenu("文件");
    QMenu * editMenu=bar->addMenu("编辑");

    //在文件下创建一个菜单项
    QAction * newAction=fileMenu->addAction("新建");
    //在新建和打开之间添加分隔符
    fileMenu->addSeparator();
    QAction * openAction=fileMenu->addAction("打开");


    //工具栏 可以有多个
    QToolBar * toolBar=new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);
    //后期设置只允许工具栏左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置浮动
    toolBar->setFloatable(false);
    //设置移动 false之后工具栏不允许移动
    toolBar->setMovable(false);
    //在工具栏中添加内容
    toolBar->addAction(newAction);
    //工具栏添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    //在工具栏中添加空间
    QPushButton *btn=new QPushButton("aa",this);
    toolBar->addWidget(btn);

    //状态栏 最多只有一个
    QStatusBar * stBar=statusBar();
    setStatusBar(stBar);
    //标签控件
    QLabel * lable=new QLabel("提示信息",this);
    stBar->addWidget(lable);
    //右侧
    QLabel * lable2=new QLabel("提示信息",this);
    stBar->addPermanentWidget(lable2);


    //铆接窗口 （浮动窗口） 可以有多个
    QDockWidget * dockWidget=new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    //设置后期停靠区域，只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);

    //设置中心部件 只能有一个
    QTextEdit * edit=new QTextEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{

}
