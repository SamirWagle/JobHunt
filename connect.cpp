#include <QtSql>

class connect{
public:
QSqlDatabase mydb;

void connclose ()
{
mydb.close();
mydb.removeDatabase(QSqlDatabase::defaultConnection);
}


bool connopen()
{
    mydb.open();
    //QString path= QCoreApplication::applicationDirPath()+"/database.db";
    QDir dir("../login_app2");
    QString path = dir.absolutePath()+"/database.db";
    qDebug()<<(path);
/*QSqlDatabase*/ mydb=QSqlDatabase::addDatabase("QSQLITE");
//mydb.setDatabaseName("C:/Users/nisch/Desktop/login_app2/database.db");
mydb.setDatabaseName(path);
if (mydb.open())
{
qDebug()<<("Successful ");
return true;}
else{
    qDebug()<<("Failed");
    return false;
}
}
};
