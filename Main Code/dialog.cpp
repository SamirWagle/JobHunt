#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "changepassjobseek.h"
#include<QPixmap>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap sjob(":/resources/image/appi.png");
    ui->label_sj->setPixmap(sjob.scaled(270,270,Qt::KeepAspectRatio));
    QPixmap ajob(":/resources/image/apjob.png");
    ui->label_aj->setPixmap(ajob.scaled(250,250,Qt::KeepAspectRatio));
    QPixmap vprof(":/resources/image/vprofile.png");
    ui->label_vp->setPixmap(vprof.scaled(250,250,Qt::KeepAspectRatio));
    QPixmap jhlog(":/resources/image/s.png");
    ui->label_jhlogo->setPixmap(jhlog.scaled(150,150,Qt::KeepAspectRatio));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_logout_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void Dialog::on_pushButton_cp_clicked()
{
    hide();
    cpjk = new changepassjobseek(this);
    cpjk->show();

}


void Dialog::on_pushButton_sj_clicked()
{
    hide();
    sjob = new searchjob(this);
    sjob->show();
}


void Dialog::on_pushButton_aj_clicked()
{
    hide();
    apjob = new appliedjob(this);
    apjob->show();
}


void Dialog::on_pushButton_vp_clicked()
{
    hide();
    vpjob = new viewprofile(this);
    vpjob->show();
}

