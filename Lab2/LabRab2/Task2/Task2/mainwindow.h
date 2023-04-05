#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "mystack.h"
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool is_valid(QString str, int& row, int& col);

private slots:
    void on_openFileButton_clicked();

    void on_checkCodeButton_clicked();

private:
    Ui::MainWindow *ui;
    QString fileAdress, line;
    bool isFileOpen;
    int row, col;
};
#endif // MAINWINDOW_H
