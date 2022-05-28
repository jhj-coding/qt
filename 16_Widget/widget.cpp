#include "widget.h"
#include "ui_widget.h"

Widget::Widget(int i,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    udpSocket=new QUdpSocket(this);
    //绑定端口
    //使用组播时不能这样写
    //udpSocket->bind(i);
    udpSocket->bind(QHostAddress::AnyIPv4,i);
    //加入某个组播 QQ群 组播地址必须为D类
    udpSocket->joinMulticastGroup(QHostAddress("224.0.0.2"));
    //退出组播 udpSocket->leaveMulticastGroup(QHostAddress(""))
    setWindowTitle(QString("服务器端口为%1").arg(i));
    //当对方成功发送数据过来 自动触发readyRead
    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::dealMsg);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::dealMsg(){
    QHostAddress cliAddr;//对方地址
    quint16 port;//对方地址
    //读取对方发送的数据
    char buf[1024]={0};
    qint64 len=udpSocket->readDatagram(buf,sizeof(buf),&cliAddr,&port);
    if(len>0){
        QString str=QString("[%1:%2]%3").arg(cliAddr.toString()).arg(port).arg(buf);
        ui->textEdit->setText(str);
    }
}

void Widget::on_btn_send_clicked()
{
    //获取对方的ip和端口
    QString ip=ui->lineEdit_ip->text();
    qint16 port=ui->lineEdit_port->text().toInt();
    //获取编辑区内容
    QString str=ui->textEdit->toPlainText();
    //给ip发送内容
    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
}
