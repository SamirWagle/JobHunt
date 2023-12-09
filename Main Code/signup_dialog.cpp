#include <signup_dialog.h>
#include <ui_signup_dialog.h>
#include <QMessageBox>
#include <mainwindow.h>
#include <signup_dialog.h>
#include <QMessageBox>


signup_Dialog::signup_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup_Dialog)
{
    ui->setupUi(this);
MainWindow conn;
    if (conn.connopen())
    {
    ui->label_second_status->setText("Successful ");}
    else{

        ui->label_second_status->setText("Failed");
    }

    QPixmap vec(":/resources/image/reg.png");
    ui->label_signpic->setPixmap(vec.scaled(200,400));



    /*place holder*/
    ui->lineEdit_phonenum->setPlaceholderText("Phone Number");
    ui->lineEdit_address->setPlaceholderText("Address");
    ui->lineEdit_user->setPlaceholderText("User Name");
    ui->lineEdit_gmail->setPlaceholderText("Gmail");
    ui->lineEdit_pass->setPlaceholderText("Password");
    ui->lineEdit_confpass->setPlaceholderText("Confirm Password");

    //icon//
    QIcon phnnum(":/resources/image/phone.png");
    ui->lineEdit_phonenum->addAction(phnnum,QLineEdit::LeadingPosition);
    QIcon adress(":/resources/image/address.png");
    ui->lineEdit_address->addAction(adress,QLineEdit::LeadingPosition);
    QIcon use(":/resources/image/user.png");
    ui->lineEdit_user->addAction(use,QLineEdit::LeadingPosition);
    QIcon gma(":/resources/image/gmail.png");
    ui->lineEdit_gmail->addAction(gma,QLineEdit::LeadingPosition);
    QIcon pas(":/resources/image/password.jpg");
    ui->lineEdit_pass->addAction(pas,QLineEdit::LeadingPosition);
    ui->lineEdit_confpass->addAction(pas,QLineEdit::LeadingPosition);


}

signup_Dialog::~signup_Dialog()
{
    delete ui;
}

void signup_Dialog::on_pushButton_sign_clicked()
{
    MainWindow conn;

    QString pn = ui->lineEdit_phonenum->text();
    QString ad = ui->lineEdit_address->text();
    QString username = ui->lineEdit_user->text();
    QString gmail = ui->lineEdit_gmail->text();
    QString password = ui->lineEdit_pass->text();
    QString confpass = ui->lineEdit_confpass->text();
    QString type="1";

    if(pn!="" && ad!="" && username!="" && gmail!="" && password!="")
    {
        if (password ==confpass){
            hide();
            MainWindow *mainWindow = new MainWindow();
            mainWindow->show();
        }else {
            QMessageBox::information(this,"Incorrect Password","Password and Confirm Password didn't match. Please check it again");
        }

    }else {
        QMessageBox::information(this,"Incomplete Information","Please fill all the fields!!");
    }
    //



    if(!conn.connopen())
    {
        qDebug()<<"Failed to  Open Database";
        return;

    }
conn.connopen();
// mydb.open();
QSqlQuery qry;
qry.prepare("INSERT INTO user_account (username,address,phone,email,password,type) VALUES ('"+username+"','"+ad+"','"+pn+"','"+gmail+"','"+password+"','"+type+"')");

if(qry.exec())

{        conn.connclose();
    conn.connopen();
    QSqlQuery qryupdate;
    qryupdate.prepare("INSERT INTO jobseekerdetials (username, education, Fname, Lname, currentcompany) VALUES('"+username+"', 'Not Entered. Please enter it from update profile', 'Not Entered. Please enter it from update profile','Not Entered. Please enter it from update profile','Not Entered. Please enter it from update profile')");
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

};



}

void signup_Dialog::on_pushButton_cancel_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


