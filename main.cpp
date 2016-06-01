#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //QTranslator trans;
    //trans.load(":/trans_bg");
    //app.installTranslator(&trans);

    MainWindow w;
    w.show();

    return app.exec();
}
