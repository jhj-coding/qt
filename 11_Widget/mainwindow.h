#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //绘图事件
    void paintEvent(QPaintEvent *event);
    int x=0;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
