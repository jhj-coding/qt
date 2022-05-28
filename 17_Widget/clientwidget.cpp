#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    isStrat=true;
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::readyRead,[=](){
        //取出接收的内容
        QByteArray array=tcpSocket->readAll();
        if(isStrat==true){
            //头信息
            isStrat=false;
            fileName=QString(array).section("##",0,0);
            fileSize=QString(array).section("##",1,1).toInt();
            recvSize=0;

            file.setFileName(fileName);
            bool isOk=file.open(QIODevice::WriteOnly);
            if(isOk==false){
                qDebug()<<"写失败";
            }
        }else{
            //文件信息
            qint64 len=file.write(array);
            recvSize+=len;
            if(recvSize==fileSize){
                file.close();
                QMessageBox::information(this,"完成","文件接收完成");
                tcpSocket->disconnectFromHost();
                tcpSocket->close();
            }
        }
    });
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_btn_connect_clicked()
{
    //获取服务器ip和端口
    QString ip=ui->ip->text();
    qint64 port=ui->port->text().toInt();
    tcpSocket->connectToHost(QHostAddress(ip),port);
}
