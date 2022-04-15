#include "launcher.h"
#include "ui_launcher.h"
#include "creatcount.h"
#include "goodslist.h"
#include "QDoubleValidator"

launcher::launcher(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::launcher)
{
    ui->setupUi(this);

    QDoubleValidator *validator = new QDoubleValidator(this);
    ui->userNameEdit->setValidator(validator);
    //创建数据库
    creatDB();
    //创建数据表
    creatTable();
    this->setWindowFlag(Qt::FramelessWindowHint);
}
launcher::~launcher()
{
    delete ui;
}

void launcher::creatDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");//创建
    db.setDatabaseName("goodsManagement.db");
    if(db.open() == true)
    {
        qDebug()<<"数据库创建/打开成功！";
    }else
    {
        qDebug()<<"数据库创建/打开失败！";
    }

}
//创建数据表
void launcher::creatTable()
{
    QSqlQuery query;
    QString str = QString("CREATE TABLE acount("
                          "userName INT PRIMARY KEY NOT NULL,"
                          "psw TEXT NOT NULL)");
    if(query.exec(str) == false){
        qDebug()<<str;
    }else {
        qDebug()<<"创建数据表成功！";
    }
}
//转到注册界面
void launcher::on_creatCountButton_clicked()
{
    creatCount *creat = new creatCount;
    creat->show();
}
//执行登录操作
void launcher::on_loginButton_clicked()
{

    QSqlQuery query;
    value.usrName = ui->userNameEdit->text().toUInt();   //获取输入账号
    QString psw = ui->passwordEdit->text();             //获取输入密码

    QString str = QString("SELECT * FROM acount WHERE userName = %1").arg(value.usrName);

    if(query.exec(str) == true)
    {
        if(query.next())
        {
            int name = query.value(0).toInt();
            QString pswin = query.value(1).toString();
            qDebug()<<QString("name : %1 , psw : '%2' ").arg(name).arg(pswin);
            if(pswin == psw)
            {
                qDebug()<<"登录成功";
                GoodsList *list = new GoodsList;
                list->show();
                close();
            }
            else {
                QMessageBox messageBox;
                messageBox.setIcon(QMessageBox::Warning);
                messageBox.setWindowTitle("提示");
                messageBox.setText("密码错误");

                messageBox.exec();
                qDebug()<<"密码错误";
            }
        }
        else {
            QMessageBox messageBox;
            messageBox.setIcon(QMessageBox::Warning);
            messageBox.setWindowTitle("提示");
            messageBox.setText("该用户名未注册");

            messageBox.exec();
            qDebug()<<"该用户名未注册";
        }
    }
    else {
        qDebug()<<QString("运行失败");
    }

}

void launcher::on_quitButton_clicked()
{
    close();
}
