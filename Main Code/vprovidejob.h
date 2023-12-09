#ifndef VPROVIDEJOB_H
#define VPROVIDEJOB_H

#include <QDialog>

namespace Ui {
class vprovidejob;
}

class vprovidejob : public QDialog
{
    Q_OBJECT

public:
    explicit vprovidejob(QWidget *parent = nullptr);
    ~vprovidejob();

private slots:

    void on_pushButton_back_clicked();
    void on_pushButton_clicked();

    void on_listView_applicants_activated(const QModelIndex &index);

    void on_pushButton_accept_clicked();

    void on_pushButton_decline_clicked();

private:
    Ui::vprovidejob *ui;
};

#endif // VPROVIDEJOB_H
