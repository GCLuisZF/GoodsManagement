#include "record.h"
#include "ui_record.h"
#include "globalvalue.h"

Record::Record(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Record)
{
    ui->setupUi(this);
    queryTable();

}

Record::~Record()
{
    delete ui;
}

void Record::queryTable()
{
    GlobalValue value;
    QString str = QString("SELECT * FROM B%1").arg(value.usrName);
    model.setQuery(str);
    ui->tableView->setModel(&model);
}
