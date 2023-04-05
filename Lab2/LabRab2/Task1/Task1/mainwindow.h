#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mylist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void saveFile();

private slots:
    void on_openFileButton_clicked(bool firtsTime);

    void on_fullListButton_clicked();

    void on_dataByFieldButton_clicked();

    void on_addBookButton_clicked();

    void on_deleteBookButton_clicked();

    void on_sortButton_clicked();

private:
    Ui::MainWindow *ui;
    QString fileAdress;
    int booksNumber;
    MyList LIST;
};
#endif // MAINWINDOW_H
