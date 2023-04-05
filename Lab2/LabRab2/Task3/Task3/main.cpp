#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(820, 120);
    w.setWindowTitle("Task3");
    w.show();
    return a.exec();
}
