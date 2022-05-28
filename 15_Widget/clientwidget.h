#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();

private slots:
    void on_connect_clicked();

    void on_send_clicked();

    void on_close_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket *tcpSocket;//通信套接字
};

#endif // CLIENTWIDGET_H
