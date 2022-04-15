#ifndef RECORD_H
#define RECORD_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QDoubleValidator>

namespace Ui {
class Record;
}

class Record : public QDialog
{
    Q_OBJECT

public:
    explicit Record(QWidget *parent = nullptr);
    ~Record();

private:
    void queryTable();

private:
    Ui::Record *ui;
    QSqlQueryModel model;

};

#endif // RECORD_H
