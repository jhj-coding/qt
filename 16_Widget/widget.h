#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>//UDP套接字
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(int i=8888,QWidget *parent = 0);
    ~Widget();
    void dealMsg();//处理对方发过来的数据
private slots:
    void on_btn_send_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
};

#endif // WIDGET_H
