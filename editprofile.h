#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QDialog>

namespace Ui {
class editprofile;
}

class editprofile : public QDialog
{
    Q_OBJECT

public:
    explicit editprofile(QWidget *parent = nullptr);
    ~editprofile();

private slots:
    void on_pushButton_cancelep_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::editprofile *ui;
};

#endif // EDITPROFILE_H
