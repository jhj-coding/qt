#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <QSqlTableModel>
#include <QSqlRecord>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<QSqlDatabase::drivers();
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("student");

    //打开数据库
    if(!db.open()){
        qDebug()<<db.lastError().text();
        return;
    }
    //设置模型
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("student");//制定使用哪个表
    //把model放到View
    ui->tableView->setModel(model);
    //显示数据
    model->select();
    //将表头第几个变为什么标题
   // model->setHeaderData(0,Qt::Horizontal,"学号");
    //设置手动提交修改
    //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //执行手动提交
    //model->submitAll();
    //取消所有动作
    //model->revertAll();
    //设置不允许修改
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //增加数据
    //添加空记录
//    QSqlRecord record=model->record();
//    //获取行号
//    int row=model->rowCount();
//    model->insertRecord(row,record);

    //取出选中的模型
    QItemSelectionModel *sModel=ui->tableView->selectionModel();
    //取出选中的索引
    QModelIndexList list=sModel->selectedRows();
    for(int i=0;i<list.size();i++)
    {
        model->removeRow(list.at(i).row());
    }


    //查找
    //取出where后面的关键字符串放入下面函数的参数中
    model->setFilter();
    model->select();
    //QSqlQuery query;
    //创建数据库 插入 删除
    //query.exec("INSERT INTO student (xueHao) VALUES ('181451081115');");
    //预处理 占位符 批量插入 odbc风格
//    query.prepare("INSERT INTO student (xueHao) VALUES (?);");
//    QVariantList xueHao;
//    xueHao<<"181451081113"<<"181451081139";
//    query.addBindValue(xueHao);
//    query.execBatch();
    //预处理 占位符 批量插入 oracle风格
//    query.prepare("INSERT INTO student (xueHao) VALUES (:xueHao);");
//    QVariantList xueHao;
//    xueHao<<"181451081110"<<"181451081130";
//    query.bindValue(":xueHao",xueHao);
//    query.execBatch();
    //开启事务
//    QSqlDatabase::database().transaction();
//    QSqlQuery query1;
//    query1.exec("delete from student where xuehao = '181451081110'");
//    //执行事务
//    QSqlDatabase::database().commit();
//    //回滚事务
//    QSqlDatabase::database().rollback();
//    query.exec("select * from student");
//    while(query.next()){//遍历
//        qDebug()<<query.value(0).toString()<<query.value("xueHao").toString();
//    }
    //修改
    //qDebug()<<query.exec("update student set zhuanYeBanJi='11' where xueHao = '181451081111'");
}

Widget::~Widget()
{
    delete ui;
}
