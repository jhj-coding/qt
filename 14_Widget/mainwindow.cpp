#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.translate(100,100);
    painter.setPen(QPen(Qt::blue));
    for(int i=0;i<9;i++){

            painter.drawLine(QPoint(0,i*10),QPoint(80,i*10));
            painter.drawLine(QPoint(i*10,0),QPoint(i*10,80));

    }
}
