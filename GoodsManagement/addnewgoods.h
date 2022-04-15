#ifndef ADDNEWGOODS_H
#define ADDNEWGOODS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QDoubleValidator>


namespace Ui {
class AddNewGoods;
}

class AddNewGoods : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewGoods(QWidget *parent = nullptr);
    ~AddNewGoods();

private slots:
    void on_okButton_clicked();

private:
    Ui::AddNewGoods *ui;

signals:
    void refresh();
};

#endif // ADDNEWGOODS_H
