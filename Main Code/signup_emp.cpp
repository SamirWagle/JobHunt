#include "signup_emp.h"
#include "ui_signup_emp.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "global.h"
signup_emp::signup_emp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup_emp)
{
    ui->setupUi(this);
    MainWindow conn;
        if (conn.connopen())
        {
        ui->label_stat->setText("Successful ");}
        else{

            ui->label_stat->setText("Failed");
        }



    QPixmap vec1(":/resources/image/reg.png");
    ui->label_signpic->setPixmap(vec1.scaled(200,400));



    /*place holder*/
    ui->lineEdit_phonenumemp->setPlaceholderText("Phone Number");
    ui->lineEdit_addressemp->setPlaceholderText("Address");
    ui->lineEdit_useremp->setPlaceholderText("User Name");
    ui->lineEdit_gmailemp->setPlaceholderText("Gmail");
    ui->lineEdit_passemp->setPlaceholderText("Password");
    ui->lineEdit_confpassemp->setPlaceholderText("Confirm Password");

    //icon//
    QIcon phnnum(":/resources/image/phone.png");
    ui->lineEdit_phonenumemp->addAction(phnnum,QLineEdit::LeadingPosition);
    QIcon adress(":/resources/image/address.png");
    ui->lineEdit_addressemp->addAction(adress,QLineEdit::LeadingPosition);
    QIcon use(":/resources/image/user.png");
    ui->lineEdit_useremp->addAction(use,QLineEdit::LeadingPosition);
    QIcon gma(":/resources/image/gmail.png");
    ui->lineEdit_gmailemp->addAction(gma,QLineEdit::LeadingPosition);
    QIcon pas(":/resources/image/password.jpg");
    ui->lineEdit_passemp->addAction(pas,QLineEdit::LeadingPosition);
    ui->lineEdit_confpassemp->addAction(pas,QLineEdit::LeadingPosition);


}

signup_emp::~signup_emp()
{
    delete ui;
}

void signup_emp::on_pushButton_cancelemp_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void signup_emp::on_pushButton_signemp_clicked()
{
    QString pnemp = ui->lineEdit_phonenumemp->text();
    QString ademp = ui->lineEdit_addressemp->text();
    QString username = ui->lineEdit_useremp->text();
    QString gmail = ui->lineEdit_gmailemp->text();
    QString password = ui->lineEdit_passemp->text();
    QString confpassemp = ui->lineEdit_confpassemp->text();
    QString type="2";

    if(pnemp!="" && ademp!="" && username!="" && gmail!="" && password!="")
    {
        if (password == confpassemp){
            MainWindow conn;

            if(!conn.connopen())
            {
                qDebug()<<"Failed to  Open Database";
                return;

            }

        conn.connopen();
        QSqlQuery qry;
        qry.prepare("INSERT INTO user_account (username,address,phone,email,password,type) VALUES ('"+username+"','"+ademp+"','"+pnemp+"','"+gmail+"','"+password+"','"+type+"')");


        if(qry.exec())

        {

        conn.connclose();
        conn.connopen();
        QSqlQuery qryupdate;
        qryupdate.prepare("INSERT INTO employerdetials (username, CompName, Description) VALUES('"+username+"', 'Not Entered. Please enter it from update profile', 'Not Entered. Please enter it from update profile')");
        QMessageBox::critical(this,tr("Data Added Successfully"),tr("Data added Successfully"));
        if(qryupdate.exec())
        {
        conn.connclose();
        QMessageBox::critical(this,tr("Data Added Successfully"),tr("Data added Successfully"));
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),qryupdate.lastError().text());

        }

        }
        else
        {
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());

        }


            hide();
            MainWindow *mainWindow = new MainWindow();
            mainWindow->show();
        }else {
            QMessageBox::information(this,"Incorrect Password","Password and Confirm Password didn't match. Please check it again");
        }

    }else {
        QMessageBox::information(this,"Incomplete Information","Please fill all the fields!!");
    }


/*QSqlQuery qry2;
conn.connopen();
qry2.prepare("INSERT INTO employerdetials (username) VALUES('"+username+"')");
if(qry2.exec())

{
QMessageBox::critical(this,tr("Data Added Successfully"),tr("Data added Successfully"));
conn.connclose();
}
else
{
    QMessageBox::critical(this,tr("error::"),qry2.lastError().text());

};
*/

}

