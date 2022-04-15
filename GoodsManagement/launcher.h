#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QDialog>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <globalvalue.h>

QT_BEGIN_NAMESPACE
namespace Ui { class launcher; }
QT_END_NAMESPACE

class launcher : public QDialog
{
    Q_OBJECT

public:
    launcher(QWidget *parent = nullptr);
    ~launcher();

private slots:
    void on_creatCountButton_clicked();

    void on_loginButton_clicked();

    void on_quitButton_clicked();

private:
    //创建数据库
    void creatDB();
    //创建数据表
    void creatTable();

private:
    Ui::launcher *ui;
    QSqlDatabase db; //建立Qt和数据库链接
    QSqlQueryModel model; //用于保存结果集
    GlobalValue value; //全局变量
};
#endif // LAUNCHER_H
