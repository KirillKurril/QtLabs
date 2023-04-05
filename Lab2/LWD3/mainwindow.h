#include "rpn.h"
#include "tablecomponent.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    tableComponent* RowsComp;
    int rows_counter = 0;
    Ui::MainWindow *ui;
    int columnsCounter = -1;
    QString fileName = "C:/C++/Labs/Lab2/LWD3/text.txt";
};
#endif // MAINWINDOW_H
