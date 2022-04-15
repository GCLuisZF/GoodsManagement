#include "deletegoods.h"
#include "ui_deletegoods.h"
#include "globalvalue.h"


DeleteGoods::DeleteGoods(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteGoods)
{
    ui->setupUi(this);
    connect(this, SIGNAL(refresh()), parent, SLOT(refresh()));
}

DeleteGoods::~DeleteGoods()
{
    delete ui;
}

//删除操作
void DeleteGoods::on_deleteButton_clicked()
{
    GlobalValue value;
    QSqlQuery query;
    int id = ui->lineEdit->text().toUInt();
    QString str = QString("delete from A%1 where 编号 = %2").arg(value.usrName).arg(id);
    query.exec(str);
    emit this->refresh();
}
