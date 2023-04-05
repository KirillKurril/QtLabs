#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ctime>
#include <fvector.cpp>
#include <QMainWindow>
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

    void getSmoll();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    DVector<int> vec1;
    DVector<int> vec2;
};
#endif // MAINWINDOW_H
