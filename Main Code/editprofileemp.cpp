#include "editprofileemp.h"
#include "ui_editprofileemp.h"
#include "vprofileemp.h"
#include <QPixmap>
#include"mainwindow.h"
#include "QMessageBox"
#include "global.h"


editprofileemp::editprofileemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editprofileemp)
{
    MainWindow conn;
       conn.connopen();
    ui->setupUi(this);
    if (conn.connopen())
        {


        ui->label_suces->setText("Successful ");}
        else{


            ui->label_suces->setText("Failed");
        }

    QPixmap picupe(":/resources/image/updateicon.png");
    ui->label_eppf->setPixmap(picupe.scaled(70,70,Qt::KeepAspectRatio));
}

editprofileemp::~editprofileemp()
{
    delete ui;
}

void editprofileemp::on_pushButton_saveemp_clicked()
{
MainWindow conn;
    QString pn = ui->lineEdit_phno->text();
        QString adrs = ui->lineEdit_address->text();
        QString name = ui->lineEdit_name->text();
        QString desc = ui->lineEdit_desc->text();
        QString id= "1";

        if(adrs.isEmpty() || name.isEmpty() || desc.isEmpty() || pn.isEmpty()){
            QMessageBox::critical(this,tr("Error"),tr("Please fill all the fields"));
            return;
        }
    conn.connopen();

    QSqlQuery qry;
    //qry.prepare("UPDATE employerdetials SET phone='"+pn+"' WHERE id='"+id+"'" );
    //WHERE id='"++"'");
   // qry.prepare("UPDATE emplotyerdetials SET address='"+adrs+"' WHERE id='"+id+"'");
   // qry.prepare("UPDATE employerdetials SET CompName='"+name+"' WHERE id='"+id+"'");

qry.prepare("UPDATE employerdetials SET CompName='"+name+"',Description='"+desc+"' WHERE username='"+tempid+"'");


//
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Edit"),tr("Name and Description Updated Successfully"));
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


void editprofileemp::on_pushButton_cemp_clicked()
{
    hide();
    vprofileemp *vemp = new vprofileemp(this);
    vemp->show();
}

