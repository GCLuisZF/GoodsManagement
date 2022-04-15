#include "creatcount.h"
#include "ui_creatcount.h"
#include "QTime"

creatCount::creatCount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creatCount)
{
    ui->setupUi(this);
    QValidator *validator = new QIntValidator(this);
    ui->userName->setValidator(validator);
}

creatCount::~creatCount()
{
    delete ui;
}
//注册操作
void creatCount::on_ok_clicked()
{
    int userName = ui->userName->text().toInt();
    QString psw = ui->psw->text();
    QString psw2 = ui->psw_2->text();
    if(psw == psw2 and userName > 100000)
    {
        QSqlQuery query;
        QString str = QString("INSERT INTO acount VALUES(%1,'%2')"
                                  ).arg(userName).arg(psw);
        if(query.exec(str) == false){
            qDebug()<<str;
        }else {
            qDebug()<<"注册成功";
            //初始化商品列表
            QString str2 = QString("CREATE TABLE A%1("
                                  "编号 INT PRIMARY KEY NOT NULL,"
                                  "名称 TEXT NOT NULL,"
                                  "单位 TEXT NOT NULL,"
                                  "价格 DOUBLE NOT NULL,"
                                  "数量 INT NOT NULL)").arg(userName);
            if(query.exec(str2) == false)
            {
                qDebug()<<str2;
            }
            QString str3 = QString("INSERT INTO A%1 VALUES(1001,'冰红茶','瓶',3,100)").arg(userName);
            query.exec(str3);
            str3 = QString("INSERT INTO A%1 VALUES(1002,'iphone13','台',7499,10)").arg(userName);
            query.exec(str3);
            str3 = QString("INSERT INTO A%1 VALUES(1003,'张建鑫的拥抱','个',9.9,99)").arg(userName);
            query.exec(str3);
            //初始化操作记录列表
            str2 = QString("CREATE TABLE B%1("
                            "时间 TEXT NOT NULL,"
                            "操作 TEXT NOT NULL,"
                            "数量 TEXT NOT NULL,"
                            "操作账号 TEXT NOT NULL)").arg(userName);
            query.exec(str2);
            //记录创建账户时间
            QDateTime time = QDateTime::currentDateTime();
            QString currentTime = time.toString("yyyy.MM.dd hh:mm:ss");
            str3 = QString("INSERT INTO B%1 VALUES('%2','注册账号:%3','1','%4')").arg(userName).arg(currentTime).arg(userName).arg(userName);
            qDebug()<<str3;
            query.exec(str3);
        }
    }
    else{
        qDebug()<<"两次密码不一致 或 用户名设置有问题";
    }
}
//返回登录界面
void creatCount::on_cancel_clicked()
{
    close();
}
