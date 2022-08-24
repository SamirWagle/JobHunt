#include "appliedjob.h"
#include "ui_appliedjob.h"
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

QString jobid1;
appliedjob::appliedjob(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::appliedjob)
{
    ui->setupUi(this);

    QPixmap sjob(":/resources/image/jobsearch.png");
    ui->label_scj->setPixmap(sjob.scaled(50,50,Qt::KeepAspectRatio));
    QPixmap vpa(":/resources/image/jober.png");
    ui->label_vieww->setPixmap(vpa.scaled(150,150,Qt::KeepAspectRatio));
    MainWindow conn;
    conn.connopen();
      static QSqlQueryModel modal;
        modal.setQuery("SELECT JobId,JobName,JobAddress,Qualification,Salary,JobType,Employer FROM applicants WHERE Applicant ='"+tempid+"'");
      ui->tableView->setModel(&modal);
      conn.connclose();
}

appliedjob::~appliedjob()
{
    delete ui;
}

void appliedjob::on_pushButton_backapjob_clicked()
{
    hide();
    Dialog *secdialog =new Dialog(this);
    secdialog->show();
}


void appliedjob::on_tableView_activated(const QModelIndex &index)
{
    MainWindow conn;
    conn.connopen();
    QString status,reply;
    QString val=ui->tableView->model()->data(index).toString();
     //ui->label_test1->setText(val);
     //ui->label_test2->setText(tempid);
    QSqlQuery qry4;
    qry4.prepare("SELECT * FROM applicants where Applicant='"+tempid+"' AND JobId= '"+val+"'");
    if(qry4.exec()){
        while(qry4.next()){
             ui->label_jobid->setText(qry4.value(0).toString());
             ui->label_jobname->setText(qry4.value(1).toString());
             ui->label_employer1->setText(qry4.value(6).toString());
             ui->label_username->setText(qry4.value(7).toString());
             status= qry4.value(8).toString();
    }

    }
    conn.connclose();

    if (status=="0"){
        reply="Your Application is Still Under Evaluation.Please wait patiently for our call.";
    }
    else if(status=="1"){
        reply="Congratulations You are Selected for next round of Selection : Interview.Please visit our office for further information";
    }
    else{
         reply="Sorry your application was rejected .Please apply next time.";
    }

    ui->label_status->setText(reply);
}

