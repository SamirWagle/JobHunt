#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

#include <QPixmap>
#include "global.h"
#include <global.cpp>
/////mydb.isopen ko place ma connopen ra connclose function rakheko ho @Samir Wagle //
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // /*QSqlDatabase*/ mydb=QSqlDatabase::addDatabase("QSQLITE");
   // mydb.setDatabaseName("C:/Users/lenovo/Desktop/login_app/database.db");
    if (connopen())
    {
    ui->label_suces->setText("Successful ");
    connclose();}
    else{
        ui->label_suces->setText("Failed");
        connclose();
    }
    //mydb.close();




    QPixmap pix(":/resources/image/jobi.png");
    ui->label_pic->setPixmap(pix.scaled(250,250,Qt::KeepAspectRatio));
    QPixmap pic_1(":/resources/image/pp.png");
    ui->label_2->setPixmap(pic_1.scaled(25,25,Qt::KeepAspectRatio));
    QPixmap pic_2(":/resources/image/pass.jpg");
    ui->label_3->setPixmap(pic_2.scaled(20,20,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

        if(!connopen())
        {
            qDebug()<<"Failed to  Open Database";
            return;

        }
    connopen();
   // mydb.open();
    QSqlQuery qry("SELECT type FROM user_account where username='"+username+"' and password='"+password+"'");
    //qry.prepare("SELECT type FROM user_account where username='"+username+"' and password='"+password+"'");
    tempid = username;
    if(qry.exec())

    {
        int count=0;
        while(qry.next())
        {count++;
        }
        qry.previous();
if(count==1)
{
    ui->label_suces->setText(qry.value(0).toString());
        if(qry.value(0)=="1"){
    connclose();
    // QMessageBox::information(this,"Login","Username and Password is correct");
     hide();
     secdialog = new Dialog(this);
     secdialog->show();
   }else if(qry.value(0)=="2"){
         connclose();
         hide();
         emp =new employer(this);
         emp->show();
    }
}

if (count<1)
{
    QMessageBox::information(this,"Login","Username or Password is incorrect");


connclose();
    }
    }
 /*   if (username == "test" && password == "test"){

       // QMessageBox::information(this,"Login","Username and Password is correct");
        hide();
        secdialog = new Dialog(this);
        secdialog->show();
      //  ui->statusbar->showMessage("Username and Password is correct", 5000);
    }*/


    // yo bhanda tala ko comment upper side ma chaina sakxa haai
/* Samir Wagle*/
  /*if (username == "test1" && password =="test1")
   {
       hide();
        emp =new employer(this);
        emp->show();
    }else
    {
        QMessageBox::information(this,"Login","Username or Password is incorrect");
        ui->statusbar->showMessage("Username and Password is incorrect", 5000);
    }*/
}


void MainWindow::on_pushButton_signup_clicked()
{
    hide();
    thirddialog = new signup_Dialog(this);
    thirddialog->show();
}


void MainWindow::on_pushButton_signupemp_clicked()
{
    hide();
    siemp = new signup_emp(this);
    siemp->show();
}


void MainWindow::on_checkBox_login_stateChanged(int arg1)
{
    switch(arg1)
    {
    case 0:
        /*hides password*/
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        break;
    case 2:
        /*shows password*/
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
        break;
    }
}

