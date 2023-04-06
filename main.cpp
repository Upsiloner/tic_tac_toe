#include "mainwindow.h"
#include "info.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    info i;
    i.show();
    return a.exec();
}
