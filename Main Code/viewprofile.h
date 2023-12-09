#ifndef VIEWPROFILE_H
#define VIEWPROFILE_H

#include <QDialog>

namespace Ui {
class viewprofile;
}

class viewprofile : public QDialog
{
    Q_OBJECT

public:
    explicit viewprofile(QWidget *parent = nullptr);
    ~viewprofile();

private slots:
    void on_pushButton_backvp_clicked();

    void on_pushButton_editvp_clicked();

private:
    Ui::viewprofile *ui;

};

#endif // VIEWPROFILE_H
