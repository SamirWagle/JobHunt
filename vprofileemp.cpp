
#include "vprofileemp.h"
#include "ui_vprofileemp.h"
#include "employer.h"
#include "editprofileemp.h"
#include "global.h"
#include "connect.cpp"
#include "QPixmap"


vprofileemp::vprofileemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vprofileemp)
{
    ui->setupUi(this);
    QPixmap vv(":/resources/image/p.png");
    ui->label_vppic->setPixmap(vv.scaled(70,70,Qt::KeepAspectRatio));

    class connect conn;
    conn.connopen();
    QSqlQuery view("select address,phone,email from user_account where username='"+tempid+"'");
    qDebug()<<(tempid);
    if(view.exec()){
        view.first();
       // ui->label_vpe1->setText(view.value(0).toString());
        ui->label_vpe2->setText(view.value(2).toString());
        ui->label_vpe3->setText(view.value(1).toString());
        ui->label_vpe4->setText(view.value(0).toString());
        //ui->label_edu->setText(view.value(3).toString());
    }
    conn.connclose();
    conn.connopen();

    QSqlQuery more("select CompName,Description from employerdetials where username='"+tempid+"'");
    if(more.exec()){
        while(more.next()){
            ui->label_vpe1->setText(more.value(0).toString());
            ui->label_vpe5->setText(more.value(1).toString());
        }



    }
conn.connclose();
}

vprofileemp::~vprofileemp()
{
    delete ui;
}

void vprofileemp::on_pushButton_backvj_clicked()
{
    hide();
    employer *emp = new employer(this);
    emp->show();
}


void vprofileemp::on_pushButton_editvj_clicked()
{
    hide();
    editprofileemp *epfemp =new editprofileemp(this);
    epfemp->show();
}

