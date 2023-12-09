#ifndef CHANGEPASSJOBSEEK_H
#define CHANGEPASSJOBSEEK_H

#include <QDialog>

namespace Ui {
class changepassjobseek;
}

class changepassjobseek : public QDialog
{
    Q_OBJECT

public:
    explicit changepassjobseek(QWidget *parent = nullptr);
    ~changepassjobseek();

private slots:
    void on_pushButton_setpass_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::changepassjobseek *ui;
};

#endif // CHANGEPASSJOBSEEK_H
