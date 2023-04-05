#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QChar>
#include "mystack.h"
#include "mystackdouble.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool is_valid(QString s);
    QString OPZ(QString str);
    double evaluation(QString line);

private slots:
    void on_evaluate2_clicked();

    void on_evaluate1_clicked();

private:
    Ui::MainWindow *ui;
    QString answer;
};
#endif // MAINWINDOW_H
