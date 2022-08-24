#include "vprovidejob.h"
#include "ui_vprovidejob.h"
#include <QPixmap>
#include "dialog.h"
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QDebug>
#include <QTextEdit>
#include<QMessageBox>
#include "global.h"
#include<QSqlError>
#include<mainwindow.h>
#include <QPixmap>

QString val,jobid;

vprovidejob::vprovidejob(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vprovidejob)
{
    ui->setupUi(this);
    QPixmap as(":/resources/image/offer.png");
    ui->label_off->setPixmap(as.scaled(100,100,Qt::KeepAspectRatio));
    MainWindow conn;

            conn.connopen();
              static QSqlQueryModel modal1;
             modal1.setQuery("SELECT JobId FROM joblist WHERE Employer='"+tempid+"'");
              ui->comboBox->setModel(&modal1);
              conn.connclose();
}

vprovidejob::~vprovidejob()
{
    delete ui;
}



void vprovidejob::on_pushButton_back_clicked()
{
    hide();
   employer *emp =new employer(this);
   emp->show();
}


void vprovidejob::on_pushButton_clicked()
{

    MainWindow conn;
     jobid=ui->comboBox->currentText();

       conn.connopen();
       static QSqlQueryModel modal;
       modal.setQuery("SELECT Applicant FROM applicants WHERE Employer='"+tempid+"' AND JobId='"+jobid+"'");
       ui->listView_applicants->setModel(&modal);
        conn.connclose();

        conn.connopen();
        QSqlQuery qry4;
        qry4.prepare("SELECT * FROM joblist where JobId = '"+jobid+"'");
        if(qry4.exec()){
            while(qry4.next()){
                ui->label_jobname->setText(qry4.value(1).toString());
                ui->label_jobaddress->setText(qry4.value(2).toString());
                ui->label_qualification->setText(qry4.value(3).toString());
                ui->label_salary->setText(qry4.value(4).toString());
                ui->label_jobtype->setText(qry4.value(5).toString());
                ui->textBrowser->setText(qry4.value(8   ).toString());
            }
            conn.connclose();
            }



}

void vprovidejob::on_listView_applicants_activated(const QModelIndex &index)
{
    MainWindow conn;
    conn.connopen();
    val=ui->listView_applicants->model()->data(index).toString();
    conn.connclose();
}


void vprovidejob::on_pushButton_accept_clicked()
{
    QString s="1";
    MainWindow conn;
    conn.connopen();
        QSqlQuery qry2;
        qry2.prepare("UPDATE applicants SET Status='"+s+"' WHERE Applicant='"+val+"' AND JobId='"+jobid+"'");
            if(qry2.exec())
            {
               QMessageBox::critical(this,tr("Status"),tr("SELECTED Successfully"));
                ui->label_test->setText(s);
                conn.connclose();
            }

            else
            {
                QMessageBox::critical(this,tr("ERROR!!!!"),qry2.lastError().text());

            }
            }


void vprovidejob::on_pushButton_decline_clicked()
{
     QString s="2";
    MainWindow conn;
    conn.connopen();
        QSqlQuery qry3;
        qry3.prepare("UPDATE applicants SET Status ='"+s+"' WHERE Applicant='"+val+"' AND JobId='"+jobid+"'");
            if(qry3.exec())
            {
                QMessageBox::critical(this,tr("Status"),tr("REJECTED Successfully"));
                ui->label_test->setText(s);
                conn.connclose();
            }

            else
            {
                QMessageBox::critical(this,tr("ERROR!!!!"),qry3.lastError().text());

            }

}

