#ifndef GOODSLIST_H
#define GOODSLIST_H

#include <QDialog>
#include <globalvalue.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QDoubleValidator>

namespace Ui {
class GoodsList;
}

class GoodsList : public QDialog
{
    Q_OBJECT

public:
    explicit GoodsList(QWidget *parent = nullptr);
    ~GoodsList();

private slots:
    void on_out_clicked();

    void on_in_clicked();

    void on_add_clicked();
    void on_deleteButton_clicked();

    void on_pushButton_5_clicked();

public slots:
    void refresh();
private:
    void queryTable();
    int checkCount(int id);

private:
    Ui::GoodsList *ui;
    GlobalValue value;
    QSqlQueryModel model;
};

#endif // GOODSLIST_H
