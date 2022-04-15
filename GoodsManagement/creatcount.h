#ifndef CREATCOUNT_H
#define CREATCOUNT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QDoubleValidator>

namespace Ui {
class creatCount;
}

class creatCount : public QDialog
{
    Q_OBJECT

public:
    explicit creatCount(QWidget *parent = nullptr);
    ~creatCount();
private:
    //创建数据库
    void creatDB();
    //创建数据表
    void creatTable();
private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::creatCount *ui;
};

#endif // CREATCOUNT_H
