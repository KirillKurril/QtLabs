#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dstring.h"
#include <QtWidgets>
#include <QFile>
#include "parser.h"

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
    void on_open_file_button_clicked();

    void on_vars_button_clicked();

    void on_structs_button_clicked();

    void on_prototypes_button_clicked();

    void on_changes_button_clicked();

    void on_local_vars_clicked();

    void on_overloads_button_clicked();

    void on_depth_button_clicked();

    void on_logic_button_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName;
    QFile file;
    QString text;
};
#endif // MAINWINDOW_H
