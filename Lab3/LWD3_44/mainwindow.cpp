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

void MainWindow::print1()
{
    QString str = "";
    for (int i = 0; i < vec1.size(); ++i)
        {
            str += QString::number(vec1[i]);
        }
    ui->textEdit->setText(str);
}

void MainWindow::print2()
{
    QString str = "";
    for (int i = 0; i < vec2.size(); ++i)
        {
            str += QString::number(vec2[i]);
        }
    ui->textEdit_2->setText(str);
}


void MainWindow::on_pushButton_clicked()
{
    size_t size = std::rand() % 6 + 5;
    //DVector<int> vec1;
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
     //DVector<int> vec2;
    vec2.resize(size);
    QString str = "";
    for (int i = 0; i < size; ++i)
        {
            vec2.push_back(std::rand() % 99 + 1);
            str += QString::number(vec2[i]);
        }
    ui->textEdit_2->setText(str);
}


void MainWindow::on_max_size_button_clicked()
{
    ui->textEdit_3->setText(QString::number(vec1.max_size()));
}


void MainWindow::on_swap_button_clicked()
{
    vec1.swap(vec2);
    QString str = "";
    for (int i = 0; i < vec1.size(); ++i)
        {
            str += QString::number(vec1[i]);
        }
    ui->textEdit->setText(str);
    str = "";
    for (int i = 0; i < vec2.size(); ++i)
        {
            str += QString::number(vec2[i]);
        }
    ui->textEdit_2->setText(str);
}


void MainWindow::on_pop_back_button_clicked()
{
    vec1.pop_back();
    vec2.pop_back();
    print1();
    print2();
}


void MainWindow::on_assign_button_clicked()
{
    //vec1.assign(ui->lineEdit_8->text().toInt(), ui->lineEdit_7->text().toInt());
    print1();
    print2();
}


void MainWindow::on_erase_button_clicked()
{
    //vec1.erase();
}

