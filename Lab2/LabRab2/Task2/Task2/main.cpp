#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(660, 520);
    w.setWindowTitle("Task2");
    w.show();
    return a.exec();
}
