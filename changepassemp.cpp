#include "changepassemp.h"
#include "ui_changepassemp.h"
#include "employer.h"
#include <QMessageBox>
#include <QPixmap>
#include <QIcon>
#include"global.h"
#include "mainwindow.h"
changepassemp::changepassemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changepassemp)
{
    ui->setupUi(this);
    QPixmap cpwd3(":/resources/image/changepass.png");
    ui->label_cpwd_2->setPixmap(cpwd3.scaled(100,100,Qt::KeepAspectRatio));


    ui->lineEdit_curpwdemp->setPlaceholderText("Current Password");
    ui->lineEdit_newpwdemp->setPlaceholderText("New Password");
    ui->lineEdit_cfnewpwdemp->setPlaceholderText("Confirm New Password");

    QIcon pwd(":/resources/image/password.jpg");
    ui->lineEdit_curpwdemp->addAction(pwd,QLineEdit::LeadingPosition);
    ui->lineEdit_newpwdemp->addAction(pwd,QLineEdit::LeadingPosition);
    ui->lineEdit_cfnewpwdemp->addAction(pwd,QLineEdit::LeadingPosition);
}

changepassemp::~changepassemp()
{
    delete ui;
}

void changepassemp::on_pushButton_setpassemp_clicked()
{
    QString cpemp =ui->lineEdit_curpwdemp->text();
    QString npemp =ui->lineEdit_newpwdemp->text();
    QString cfnwemp =ui->lineEdit_cfnewpwdemp->text();

    if(cpemp!="" && npemp!="")
    {
        if(npemp==cfnwemp)
        {
            hide();
            employer *emp = new employer();
            emp->show();

            MainWindow conn;
            conn.connopen();
            QSqlQuery qrychange;
            qrychange.prepare("UPDATE user_account SET password='"+cfnwemp+"' WHERE username='"+tempid+"'");
            if(qrychange.exec())
            {
                QMessageBox::critical(this,tr("Edit"),tr("Password Updated Successfully"));
                conn.connclose();
            }

            else
            {
                QMessageBox::critical(this,tr("ERROR!!!!"),qrychange.lastError().text());


            }
            conn.connclose();

        }else
        {
            QMessageBox::information(this,"Mismatched","New Password and Confirm New Password didn't match. Please check it again");
        }
    }else
    {
        QMessageBox::information(this,"Empty Field","Please fill the required fields!!");
    }
}


void changepassemp::on_pushButton_back1_clicked()
{
    hide();
    employer *emp = new employer();
    emp->show();
}

