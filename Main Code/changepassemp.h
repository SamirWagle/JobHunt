#ifndef CHANGEPASSEMP_H
#define CHANGEPASSEMP_H

#include <QDialog>

namespace Ui {
class changepassemp;
}

class changepassemp : public QDialog
{
    Q_OBJECT

public:
    explicit changepassemp(QWidget *parent = nullptr);
    ~changepassemp();

private slots:
    void on_pushButton_setpassemp_clicked();

    void on_pushButton_back1_clicked();

private:
    Ui::changepassemp *ui;
};

#endif // CHANGEPASSEMP_H
