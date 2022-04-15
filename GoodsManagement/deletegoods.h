#ifndef DELETEGOODS_H
#define DELETEGOODS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QDoubleValidator>

namespace Ui {
class DeleteGoods;
}

class DeleteGoods : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteGoods(QWidget *parent = nullptr);
    ~DeleteGoods();

private slots:
    void on_deleteButton_clicked();

private:
    Ui::DeleteGoods *ui;

signals:
    void refresh();
};

#endif // DELETEGOODS_H
