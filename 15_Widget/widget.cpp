#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpServer=NULL;
    tcpSocket=NULL;
    //监听套接字
    tcpServer=new QTcpServer(this);
    //监听任意ip 端口为8888
    tcpServer->listen(QHostAddress::Any,8888);
    setWindowTitle("服务器8888");
    //建立连接
    connect(tcpServer,&QTcpServer::newConnection,this,[=](){
        //取出建立好的套接字
        tcpSocket=tcpServer->nextPendingConnection();
        //获取对方的ip和端口
        QString ip=tcpSocket->peerAddress().toString();
        qint16 port=tcpSocket->peerPort();

        QString temp=QString("[%1：%2]:成功连接").arg(ip).arg(port);
        ui->text_read->setText(temp);


        connect(tcpSocket,&QTcpSocket::readyRead,this,[=](){
            //从通信套接字中取出内容
            QByteArray array=tcpSocket->readAll();
            ui->text_read->append(array);
        });
    });


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_send_clicked()
{
    if(NULL==tcpSocket){
        return;
    }
    //获取编辑区内容
    QString str=ui->text_write->toPlainText();
    //给对方发送数据 使用tcpSocket套接字
    tcpSocket->write(str.toUtf8().data());
}

void Widget::on_btn_close_clicked()
{
    if(NULL==tcpSocket){
        return;
    }
    //主动和客户端断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket=NULL;
}
