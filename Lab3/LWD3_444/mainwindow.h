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

    void print1();

    void print2();

    void achtung();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_max_size_button_clicked();

    void on_swap_button_clicked();

    void on_pop_back_button_clicked();

    void on_assign_button_clicked();

    void on_erase_button_clicked();

    void on_capacity_button_clicked();

    void on_push_back_button_clicked();

    void on_size_button_clicked();

    void on_clear_button_clicked();

    void on_empty_button_clicked();

    void on_insert_button_clicked();

    void on_emplace_button_clicked();

    void on_emplace_back_button_clicked();

    void on_textEdit_copyAvailable(bool b);

private:
    Ui::MainWindow *ui;
    DVector<int> vec1;
    DVector<int> vec2;
};
#endif // MAINWINDOW_H
