#ifndef PROVIDEJOB_H
#define PROVIDEJOB_H

#include <QDialog>

namespace Ui {
class providejob;
}

class providejob : public QDialog
{
    Q_OBJECT

public:
    explicit providejob(QWidget *parent = nullptr);
    ~providejob();

private slots:
    void on_pushButton_post_clicked();

    void on_pushButton_cancelpjob_clicked();

private:
    Ui::providejob *ui;
};

#endif // PROVIDEJOB_H
