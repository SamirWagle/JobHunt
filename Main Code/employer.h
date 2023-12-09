#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QDialog>
//#include "main.cpp"
#include "changepassemp.h"
#include "providejob.h"
#include "vprovidejob.h"
#include "vprofileemp.h"

namespace Ui {
class employer;
}

class employer : public QDialog
{
    Q_OBJECT

public:
    explicit employer(QWidget *parent = nullptr);
    ~employer();

private slots:
    void on_pushButton_logout_clicked();

    void on_pushButton_cpemp_clicked();

    void on_pushButton_pj_clicked();

    void on_pushButton_vpj_clicked();

    void on_pushButton_vpemp_clicked();

private:
    Ui::employer *ui;
    changepassemp *cpemp;
    providejob *pjob;
    vprovidejob *vpjob;
    vprofileemp *vpemp;
};

#endif // EMPLOYER_H
