#ifndef EDITPROFILEEMP_H
#define EDITPROFILEEMP_H

#include <QDialog>

namespace Ui {
class editprofileemp;
}

class editprofileemp : public QDialog
{
    Q_OBJECT

public:
    explicit editprofileemp(QWidget *parent = nullptr);
    ~editprofileemp();

private slots:
    void on_pushButton_saveemp_clicked();

    void on_pushButton_cemp_clicked();

private:
    Ui::editprofileemp *ui;
};

#endif // EDITPROFILEEMP_H
