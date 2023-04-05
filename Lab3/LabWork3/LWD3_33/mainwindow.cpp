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

void MainWindow::getSmoll()
{
    for(int i = 0; i < vec1.size();)
    {
        DVector<int> tp ;
        tp.push_back(vec1[i]);
        i++;
        tp.push_back(vec1[i]);
        i++;
        tp.push_back(vec1[i]);
        i++;
        if (tp[0] > tp[1])
            std::swap(tp[0], tp[1]);
        if (tp[1] > tp[2])
            std::swap(tp[1], tp[2]);
        if (tp[0] > tp[1])
            std::swap(tp[0], tp[1]);
        vec2.push_back(tp[1]);
        tp.del();

    }
}


void MainWindow::on_pushButton_clicked()
{
    vec1.clear();
    size_t size = std::rand() % 15 + 5;
    vec1.resize(size);
    QString str = "";
    for (int i = 0; i < size; ++i)
        {
            vec1.push_back(std::rand() % 99 + 1);
            str += QString::number(vec1[i]) + ' ';
        }
    ui->textEdit->setText(str);
}


void MainWindow::on_pushButton_2_clicked()
{

    if (vec1.size() % 3 == 1)
    {
        vec1.push_back(vec1[vec1.size()- 1]);
        vec1.push_back(vec1[vec1.size()- 1]);
    }
    if (vec1.size() % 3 == 2)
    {
        vec1.push_back((vec1[vec1.size()- 1] + vec1[vec1.size() - 2])/ 2);
    }
    getSmoll();
    QString smalls;
    for (int i = 0; i < vec2.size(); i++)
    {
        smalls += QString::number(vec2[i]) + " ";
    }
    ui->textEdit_2->setText(smalls);
    vec2.clear();
}

