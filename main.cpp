#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>

#include<QFile>
QString id;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //set the app style sheet//
    QFile styleSheetFile(":/resources/image/Hookmark.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    MainWindow w;
//    w.show();
    w.showMaximized();
    return a.exec();
}
