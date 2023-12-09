#ifndef SIGNUP_DIALOG_H
#define SIGNUP_DIALOG_H


#include <QDialog>

namespace Ui {
class signup_Dialog;
}

class signup_Dialog : public QDialog
{
    Q_OBJECT

public:
    //MainWindow conn;
    explicit signup_Dialog(QWidget *parent = nullptr);
    ~signup_Dialog();

private slots:
    void on_pushButton_sign_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::signup_Dialog *ui;
};

#endif // SIGNUP_DIALOG_H
