#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"abobus.h"
#include "masslist.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateTable(MassList* masslist);


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:

    static QString fileName;
    Ui::MainWindow *ui;
    MassList* list;
    MassList* exList;
    MassList* unexList;
};
#endif // MAINWINDOW_H
