#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //监听套接字
    tcpServer=new QTcpServer(this);
    //监听
    tcpServer->listen(QHostAddress::Any,8888);
    setWindowTitle("服务器端口为8888");
    //两个按钮默认不能点击
    ui->btn_select->setEnabled(false);
    ui->btn_send->setEnabled(false);
    //连接成功 触发newconnect
    connect(tcpServer,&QTcpServer::newConnection,this,[=](){
       //取出套接字
        tcpSocket=tcpServer->nextPendingConnection();
        //获取对方ip和端口
        QString ip=tcpSocket->peerAddress().toString();
        quint16 port=tcpSocket->peerPort();
        QString str=QString("[%1:%2]成功连接").arg(ip).arg(port);
        ui->textEdit->setText(str);
        //按钮可以
        ui->btn_select->setEnabled(true);
    });

    connect(&timer,&QTimer::timeout,this,[=](){
        timer.stop();
        sendData();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_select_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"open","../");
    if(false== path.isEmpty()){
        //获取文件信息
        fileName.clear();
        fileSize=0;
        sendSize=0;
        QFileInfo info(path);
        fileName=info.fileName();
        fileSize=info.size();
        file.setFileName(path);
        bool isOk=file.open(QIODevice::ReadOnly);
        if(!isOk){
            qDebug()<<"打开失败";
        }
        ui->textEdit->append(path);
        ui->btn_select->setEnabled(false);
        ui->btn_send->setEnabled(true);
    }else{
        qDebug()<<"选择文件路径出错";
    }
}

void MainWindow::on_btn_send_clicked()
{
    //先发送文件头
    QString head=QString("%1##%2").arg(fileName).arg(fileSize);
    qint64 len=tcpSocket->write(head.toUtf8());
    if(len>0){//头部发送成功
        //防止Tcp黏包问题 ，需要延时20ms
        timer.start(20);
    }else{
        qDebug()<<"头部信息发送失败";
        file.close();
        ui->btn_select->setEnabled(true);
        ui->btn_send->setEnabled(false);
    }
}
void MainWindow::sendData(){
    qint64 len=0;
    do{
        //每次发送4k
        char buf[4*1024]={0};
        len=0;
        len=file.read(buf,sizeof(buf));
        //发送数据 都多少发多少
        len=tcpSocket->write(buf,len);
        //发送数据要累加
        sendSize+=len;
    }while(len>0);
    if(sendSize==fileSize){
        ui->textEdit->append("文件发送完毕");
        file.close();
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    }
}
