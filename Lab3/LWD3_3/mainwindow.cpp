#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dsort.h"
#include <QDebug>

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

void MainWindow::getSmoll(DVector<int>& big, DVector<int>& small, int spinam)
{
    for(int i = 0; i < spinam;)
    {
        DVector<int> tp ;
        tp.push_back(big[i]);
        qDebug() << tp[0];
        i++;
        tp.push_back(big[i]);
        qDebug() << tp[1];
        i++;
        tp.push_back(big[i]);
        qDebug() << tp[2];
        i++;
        qDebug() << tp[0] << tp[1] << tp[2];
        //DSort::qsort(tp.data(), 0, tp.size() - 1);
        if (tp[0] > tp[1])
            std::swap(tp[0], tp[1]);
        if (tp[1] > tp[2])
            std::swap(tp[1], tp[2]);
        if (tp[0] > tp[1])
            std::swap(tp[0], tp[1]);
        qDebug() << tp[0] << tp[1] << tp[2];
        small.push_back(tp[1]);
        tp.del();

    }
}


void MainWindow::on_pushButton_clicked()
{
    const int spinamb = 11;
    int spinam = spinamb;
    DVector<int> big;
    DVector<int> small;
    for(int i = 0; i < spinam; i++)
    {
        big.push_back(ui->spinBox->value());
        big.push_back(ui->spinBox_2->value());
        big.push_back(ui->spinBox_3->value());
        big.push_back(ui->spinBox_4->value());
        big.push_back(ui->spinBox_5->value());
        big.push_back(ui->spinBox_6->value());
        big.push_back(ui->spinBox_7->value());
        big.push_back(ui->spinBox_8->value());
        big.push_back(ui->spinBox_9->value());
        big.push_back(ui->spinBox_10->value());
        big.push_back(ui->spinBox_11->value());
    }
    if(spinamb%3 == 1)
    {
        big.push_back(big[big.size() - 1]);
        big.push_back(big[big.size() - 1]);
        spinam += 2;
    }
    if(spinamb%3 == 2)
    {
        big.push_back((big[big.size() - 1] + big[big.size() - 2])/2);
        ++spinam;
    }
    QString bigs;
    for (int i = 0; i < spinamb; i++)
    {
        bigs += QString::number(big[i]) + " ";
    }
    ui->textEdit->setText(bigs);
    getSmoll(big, small, spinam);
    QString smalls;
    for (int i = 0; i < small.size(); i++)
    {
        smalls += QString::number(small[i]) + " ";
    }
    ui->textEdit_2->setText(smalls);

}

