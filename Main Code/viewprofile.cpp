#include "viewprofile.h"
#include "ui_viewprofile.h"
#include "dialog.h"
#include "editprofile.h"
#include "global.h"
#include "connect.cpp"
#include <QPixmap>

//extern QString tempid;
//qDebug()<<(tempid);
viewprofile::viewprofile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewprofile)
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

        ui->label_address->setText(view.value(0).toString());
        ui->label_phonenumber->setText(view.value(1).toString());
        ui->label_email->setText(view.value(2).toString());
         }
    conn.connclose();
    conn.connopen();

    QSqlQuery more("select Fname,Lname,education,currentcompany from jobseekerdetials where username='"+tempid+"'");
    if(more.exec()){
        while(more.next()){
            ui->label_fname->setText(more.value(0).toString());
            ui->label_lname->setText(more.value(1).toString());
            ui->label_education->setText(more.value(2).toString());
            ui->label_current->setText(more.value(3).toString());
        }

    }
conn.connclose();

}

viewprofile::~viewprofile()
{
    delete ui;
}

void viewprofile::on_pushButton_backvp_clicked()
{
    hide();
    Dialog *secdialog = new Dialog(this);
    secdialog->show();
}


void viewprofile::on_pushButton_editvp_clicked()
{
    hide();
    editprofile *epfp =new editprofile(this);
    epfp->show();
}

