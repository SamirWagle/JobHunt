#ifndef SEARCHJOB_H
#define SEARCHJOB_H

#include <QDialog>
#include<QSql>
#include<QFileInfo>
#include<QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlRecord>

namespace Ui {
class searchjob;
}

class searchjob : public QDialog
{
    Q_OBJECT


public:
    explicit searchjob(QWidget *parent = nullptr);
    ~searchjob();
    bool alreadyApplied(QString jobid, QString applicant);

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_sjob_clicked();

    void on_pushButton_apply_clicked();

    void on_tableView_search_activated(const QModelIndex &index);

private:
    Ui::searchjob *ui;
};

#endif // SEARCHJOB_H
