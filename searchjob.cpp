#include "searchjob.h"
#include "ui_searchjob.h"
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

searchjob::searchjob(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::searchjob)
{

    MainWindow conn;
    ui->setupUi(this);
    QPixmap sjob(":/resources/image/jobsearch.png");
    ui->label_scj->setPixmap(sjob.scaled(50,50,Qt::KeepAspectRatio));

    if (conn.connopen())
    {
    ui->label->setText("Successful ");
     conn.connclose();}
    else{
        ui->label->setText("Failed");
        conn.connclose();
    }

    ui->lineEdit_JobName->setPlaceholderText("Job Name");
    ui->lineEdit_JobAddress->setPlaceholderText("Job Address");
    ui->lineEdit_Qualification->setPlaceholderText("Qualification");
    ui->lineEdit_Salary->setPlaceholderText("Salary");
    ui->lineEdit_JobType->setPlaceholderText("Job Type");
    ui->lineEdit_name->setPlaceholderText("Applicant Name");
    ui->lineEdit_Employer->setPlaceholderText("Employer Name");
    ui->lineEdit_JobId->setPlaceholderText("Job Id");

}

searchjob::~searchjob()
{
    delete ui;
}

bool searchjob::alreadyApplied(QString jobid, QString applicant)
{

    MainWindow conn;
    conn.connopen();
    QSqlQuery qrynew;
        qrynew.exec("SELECT * FROM applicants WHERE Applicant = '"+applicant+"' AND JobId = '"+jobid+"'");
        if(qrynew.next()){
            return true;
            conn.connclose();
        }
        else{

            return false;
            conn.connclose();
        }

}

void searchjob::on_pushButton_back_clicked()
{
    hide();
       Dialog *secdialog =new Dialog(this);
       secdialog->show();

}


void searchjob::on_pushButton_sjob_clicked()
{

    MainWindow conn;
    conn.connopen();
        static QSqlQueryModel modal;
        QString keyword,location,low,up;
        keyword = ui->lineEdit_keyword->text();
        location=ui->comboBox_location->currentText();
        low=ui->lineEdit_lower->text();
        up=ui->lineEdit_upper->text();

        location=location.toUpper();
        keyword=keyword.toUpper();

        if(keyword.isEmpty() && location=="ALL"){
            modal.setQuery("SELECT JobId,JobName,JobAddres,Qualification,Salary,JobType FROM joblist WHERE Salary BETWEEN '"+low+"' AND '"+up+"'");

        }
        if(keyword.isEmpty() && location !="ALL"){
             modal.setQuery("SELECT JobId,JobName,JobAddres,Qualification,Salary,JobType FROM joblist WHERE JobAddres='"+location+"' AND Salary BETWEEN '"+low+"' AND '"+up+"'");

        }
        if(!keyword.isEmpty() && location=="ALL"){
            modal.setQuery("SELECT JobId,JobName,JobAddres,Qualification,Salary,JobType FROM joblist WHERE JobName='"+keyword+"' AND Salary BETWEEN '"+low+"' AND '"+up+"'");
         }
        if(!keyword.isEmpty() && location!="ALL"){
           modal.setQuery("SELECT JobId,JobName,JobAddres,Qualification,Salary,JobType FROM joblist WHERE JobName = '"+keyword+"' AND JobAddres='"+location+"' AND Salary BETWEEN '"+low+"' AND '"+up+"'");
        }
        ui->tableView_search->setModel(&modal);
        ui->label_display->setText("Click on the desired JobId to fill the form ");
        conn.connclose();
}




void searchjob::on_tableView_search_activated(const QModelIndex &index)
{
   QString val=ui->tableView_search->model()->data(index).toString();
   MainWindow conn;
    conn.connopen();
    QSqlQuery qry4;
    qry4.prepare("SELECT * FROM Joblist where JobId = '"+val+"'");
    if(qry4.exec()){
        while(qry4.next()){
            ui->lineEdit_JobId->setText(qry4.value(0).toString());
            ui->lineEdit_JobName->setText(qry4.value(1).toString());
            ui->lineEdit_JobAddress->setText(qry4.value(2).toString());
            ui->lineEdit_Qualification->setText(qry4.value(3).toString());
            ui->lineEdit_Salary->setText(qry4.value(4).toString());
            ui->lineEdit_JobType->setText(qry4.value(5).toString());
            ui->lineEdit_Employer->setText(qry4.value(6).toString());
            ui->textBrowser->setText(qry4.value(8).toString());
}
           ui->lineEdit_name->setText(tempid);
            conn.connclose();
}

}


void searchjob::on_pushButton_apply_clicked()
{
    QString jobname,username,jobaddress,jobtype,qualification,salary,jobid,employer;
    jobname = ui->lineEdit_JobName->text();
    username=ui->lineEdit_name->text();
    jobaddress=ui->lineEdit_JobAddress->text();
    qualification=ui->lineEdit_Qualification->text();
    salary=ui->lineEdit_Salary->text();
    jobtype=ui->lineEdit_JobType->text();
    jobid=ui->lineEdit_JobId->text();
    employer=ui->lineEdit_Employer->text();

    if(alreadyApplied(jobid, username)){
            QMessageBox::critical(this,tr("Apply"),tr("Already Applied"));
            return;

        }

    MainWindow conn;
    conn.connopen();
    QSqlQuery qryapply;
       //qry.prepare("INSERT INTO applicants (JobId,JobName,JobAddress,Qualification,Salary,JobType,Applicant,Employer) VALUES ("+jobid+","+jobname+","+jobaddress+","+qualification+","+salary+","+jobtype+","+username+","+employer+")");
    qryapply.prepare("INSERT INTO applicants (JobId,JobName,JobAddress,Qualification,Salary,JobType,Applicant,Employer,Status) VALUES (:jobid,:jobname,:jobaddress,:qualification,:salary,:jobtype,:username,:employer,:status)");
    qryapply.bindValue(":jobid", jobid);
    qryapply.bindValue(":jobname", jobname);
    qryapply.bindValue(":jobaddress", jobaddress);
    qryapply.bindValue(":qualification", qualification);
    qryapply.bindValue(":salary", salary);
    qryapply.bindValue(":jobtype", jobtype);
    qryapply.bindValue(":employer", employer);
    qryapply.bindValue(":username", username);
    qryapply.bindValue(":status",0);

    if(qryapply.exec())
    {
    QMessageBox::critical(this,tr("Apply"),tr("Applied Successfully"));
      ui->label_test->setText("Sucess");
      conn.connclose();

    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qryapply.lastError().text());

    };

/*
if(count>=1)
{
     QMessageBox::information(this,"Apply","Already Applied for this Job");

}
else
{
    connopen();
    QSqlQuery qry5;
    qry5.prepare("SELECT * FROM user_account where JobId='"+jobid+"' and applicant='"+tempid+"'");
    if(qry.exec())
    {
    QMessageBox::critical(this,tr("Apply"),tr("Applied Successfully"));
    connclose();
    }
}
}*/
}
