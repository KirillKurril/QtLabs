#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "good.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<Good> Goods;
    std::vector<Good> motherboards;
    std::vector<Good> processors;
    std::vector<Good> rams;
    std::vector<Good> roms;
    std::vector<Good> power_units;
    std::vector<Good> cases;
private slots:
    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
