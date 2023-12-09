#include "employer.h"
#include "ui_employer.h"
#include "mainwindow.h"
#include <QPixmap>
#include "changepassemp.h"

employer::employer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employer)
{
    ui->setupUi(this);
    QPixmap provjob(":/resources/image/projob.jpg");
    ui->label_pj->setPixmap(provjob.scaled(250,250,Qt::KeepAspectRatio));
    QPixmap viewprovjob(":/resources/image/vpj.png");
    ui->label_vpj->setPixmap(viewprovjob.scaled(270,270,Qt::KeepAspectRatio));
    QPixmap vpemp(":/resources/image/vprofile.png");
    ui->label_vp->setPixmap(vpemp.scaled(250,250,Qt::KeepAspectRatio));
    QPixmap jhlog1(":/resources/image/s.png");
    ui->label_jhlogo->setPixmap(jhlog1.scaled(150,150,Qt::KeepAspectRatio));
}

employer::~employer()
{
    delete ui;
}

void employer::on_pushButton_logout_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void employer::on_pushButton_cpemp_clicked()
{
    hide();
    cpemp = new changepassemp(this);
    cpemp->show();

}


void employer::on_pushButton_pj_clicked()
{

    hide();
    pjob = new providejob(this);
    pjob->show();

}


void employer::on_pushButton_vpj_clicked()
{
    hide();
    vpjob = new vprovidejob(this);
    vpjob->show();
}


void employer::on_pushButton_vpemp_clicked()
{
    hide();
    vpemp = new vprofileemp(this);
    vpemp->show();
}

