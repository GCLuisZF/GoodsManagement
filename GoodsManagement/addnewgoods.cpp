#include "addnewgoods.h"
#include "ui_addnewgoods.h"
#include "globalvalue.h"
#include "goodslist.h"

AddNewGoods::AddNewGoods(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewGoods)
{
    ui->setupUi(this);
    connect(this, SIGNAL(refresh()), parent, SLOT(refresh()));
}

AddNewGoods::~AddNewGoods()
{
    delete ui;
}

void AddNewGoods::on_okButton_clicked()
{
    GlobalValue value;
    QSqlQuery query;
    int id = ui->idEdit->text().toUInt();
    QString name = ui->nameEdit->text();
    QString unit = ui->unitEdit->text();
    float price = ui->priceEdit->text().toDouble();

    QString str = QString("INSERT INTO A%1 VALUES(%2,'%3','%4',%5,0)").arg(value.usrName).arg(id).arg(name).arg(unit).arg(price);
    query.exec(str);
    emit this->refresh();
}
