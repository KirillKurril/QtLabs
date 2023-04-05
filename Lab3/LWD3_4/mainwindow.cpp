#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    size_t size = std::rand() % 6 + 5;
    DVector<int> vec1;
    vec1.resize(size);
    QString str = "";
    for (int i = 0; i < size; ++i)
        {
            vec1.push_back(std::rand() % 99 + 1);
            str += QString::number(vec1[i]);
        }
    ui->textEdit->setText(str);
}


void MainWindow::on_pushButton_2_clicked()
{
    size_t size = std::rand() % 6 + 5;
     DVector<int> vec2;
    vec2.resize(size);
    QString str = "";
    for (int i = 0; i < size; ++i)
        {
            vec2.push_back(std::rand() % 99 + 1);
            str += QString::number(vec2[i]);
        }
    ui->textEdit->setText(str);
}

