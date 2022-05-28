#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
    tcpSocket=NULL;
    //分配空间指定父对象
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::connected,[=](){
       ui->textEdit_read->setText("成功和服务器建立");
    });
    connect(tcpSocket,&QTcpSocket::readyRead,[=](){
        QByteArray array=tcpSocket->readAll();
       ui->textEdit_read->append(array);
    });
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_connect_clicked()
{
    if(NULL==tcpSocket){
        return;
    }
    QString ip=ui->lineEdit_ip->text();
    qint16 port=ui->lineEdit_port->text().toInt();
    tcpSocket->connectToHost(QHostAddress(ip),port);

}

void ClientWidget::on_send_clicked()
{
    if(NULL==tcpSocket){
        return;
    }
    //获取编辑框内容
    QString str=ui->textEdit_2->toPlainText();
    tcpSocket->write(str.toUtf8().data());
}

void ClientWidget::on_close_clicked()
{
    //主动和对方断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
