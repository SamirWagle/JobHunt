#include "editprofile.h"
#include "ui_editprofile.h"
#include "viewprofile.h"
#include <QPixmap>
#include<mainwindow.h>
#include<mainwindow.cpp>
#include<global.h>
#include<QString>

editprofile::editprofile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editprofile)
{
    ui->setupUi(this);

    QPixmap picup(":/resources/image/updateicon.png");
    ui->label_uppf->setPixmap(picup.scaled(70,70,Qt::KeepAspectRatio));
}

editprofile::~editprofile()
{
    delete ui;
}

void editprofile::on_pushButton_cancelep_clicked()
{
    hide();
    viewprofile *vpjob = new viewprofile(this);
    vpjob->show();
}


void editprofile::on_pushButton_save_clicked()
{
    MainWindow conn;
        QString pn = ui->lineEdit_u3->text();
            QString adrs = ui->lineEdit_u4->text();
            QString fname = ui->lineEdit_u1->text();
            QString lname = ui->lineEdit_u2->text();
            QString education = ui->lineEdit_u5->text();
            QString current = ui->lineEdit_u6->text();
            QString id= "2";
        conn.connopen();

        QSqlQuery qry;
        qry.prepare("UPDATE jobseekerdetials SET Fname='"+fname+"',Lname='"+lname+"',education='"+education+"',currentcompany='"+current+"' WHERE username='"+tempid+"'");


        //
            if(qry.exec())
            {
                QMessageBox::critical(this,tr("Edit"),tr("FNAME,LNAME,Education and Current Company Updated Successfully"));
                conn.connclose();
            }

            else
            {
                QMessageBox::critical(this,tr("ERROR!!!!"),qry.lastError().text());


            }
            conn.connopen();
            QSqlQuery qry1;
            qry1.prepare("UPDATE user_account SET address='"+adrs+"',phone='"+pn+"' WHERE username='"+tempid+"'");
            qDebug()<<adrs<<pn<<tempid;
            if(qry1.exec())
            {
                QMessageBox::critical(this,tr("Edit"),tr("Address and Phone Number Updated Successfully"));
                conn.connclose();
            }
            else
            {
                QMessageBox::critical(this,tr("ERROR!!!!"),qry1.lastError().text());


            }

}

