#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "main.cpp"
#include "signup_dialog.h"
#include "dialog.h"
#include "employer.h"
#include "signup_emp.h"
#include<QtSql>
#include<QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
QSqlDatabase mydb;

void connclose ()
{
mydb.close();
mydb.removeDatabase(QSqlDatabase::defaultConnection);}


bool connopen()
{

    //QString path= QCoreApplication::applicationDirPath()+"/database.db";
    QDir dir("../login_app2");
    QString path = dir.absolutePath()+"/database.db";
    qDebug()<<(path);
/*QSqlDatabase*/ mydb=QSqlDatabase::addDatabase("QSQLITE");
//mydb.setDatabaseName("C:/Users/nisch/Desktop/login_app2/database.db");
mydb.setDatabaseName(path);

if (mydb.open())
{
qDebug()<<("Successful ");
return true;
    }
else{

    qDebug()<<("Failed");
    return false;
}
connclose();
}
MainWindow(QWidget *parent = nullptr);
~MainWindow();

private slots:
void on_pushButton_login_clicked();

void on_pushButton_signup_clicked();

void on_pushButton_signupemp_clicked();

void on_checkBox_login_stateChanged(int arg1);



private:
Ui::MainWindow *ui;
Dialog *secdialog;
signup_Dialog *thirddialog;
employer *emp;
signup_emp *siemp;


};
#endif // MAINWINDOW_H
