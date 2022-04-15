#include "goodslist.h"
#include "ui_goodslist.h"
#include "addnewgoods.h"
#include "deletegoods.h"
#include "record.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QDoubleValidator>

GoodsList::GoodsList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoodsList)
{
    ui->setupUi(this);
    queryTable();

}

GoodsList::~GoodsList()
{
    delete ui;
}

void GoodsList::queryTable()
{
    QString str = QString("SELECT * FROM A%1").arg(value.usrName);
    model.setQuery(str);
    ui->tableView->setModel(&model);
}
//出货操作
void GoodsList::on_out_clicked()
{
    QSqlQuery query;
    int id = ui->idEdit->text().toUInt();
    int count = ui->countEdit->text().toInt();
    if(count <= checkCount(id))
    {
        QString str = QString("update A%1 set 数量 = 数量-%2 where 编号 = %3").arg(value.usrName).arg(count).arg(id);
        query.exec(str);
        queryTable();
    }
    else{
        qDebug()<<"数量过多，存货不足";
    }

}
//进货操作
void GoodsList::on_in_clicked()
{
    QSqlQuery query;
    int id = ui->idEdit->text().toUInt();
    int count = ui->countEdit->text().toInt();
        QString str = QString("update A%1 set 数量 = 数量+%2 where 编号 = %3").arg(value.usrName).arg(count).arg(id);
        query.exec(str);
        queryTable();
}

int GoodsList::checkCount(int id)
{
    QSqlQuery query;
    int count = 0;
    QString str = QString("SELECT 数量 FROM A%1 WHERE 编号 = %2").arg(value.usrName).arg(id);
    if(query.exec(str) == true)
    {
        if(query.next())
        {
            count = query.value(0).toInt();
        }
    }
    qDebug()<<count;
    return  count;
}


//添加货品
void GoodsList::on_add_clicked()
{
    AddNewGoods *add = new AddNewGoods(this);
    add->show();
}
//刷新的槽函数
void GoodsList::refresh()
{
    queryTable();
}
//删除货品
void GoodsList::on_deleteButton_clicked()
{
    DeleteGoods *d = new DeleteGoods(this);
    d->show();
}
//操作记录
void GoodsList::on_pushButton_5_clicked()
{
    Record *record = new Record(this);
    record->show();
}
