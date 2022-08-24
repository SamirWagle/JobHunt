#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "changepassjobseek.h"
#include "searchjob.h"
#include "appliedjob.h"
#include "viewprofile.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_pushButton_logout_clicked();

    void on_pushButton_cp_clicked();

    void on_pushButton_sj_clicked();

    void on_pushButton_aj_clicked();

    void on_pushButton_vp_clicked();

private:
    Ui::Dialog *ui;
     changepassjobseek *cpjk;
     searchjob *sjob;
     appliedjob *apjob;
     viewprofile *vpjob;

};

#endif // DIALOG_H
