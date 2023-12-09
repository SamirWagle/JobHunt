#ifndef SIGNUP_EMP_H
#define SIGNUP_EMP_H

#include <QDialog>

namespace Ui {
class signup_emp;
}

class signup_emp : public QDialog
{
    Q_OBJECT

public:
    explicit signup_emp(QWidget *parent = nullptr);
    ~signup_emp();

private slots:
    void on_pushButton_cancelemp_clicked();

    void on_pushButton_signemp_clicked();

private:
    Ui::signup_emp *ui;
};

#endif // SIGNUP_EMP_H
