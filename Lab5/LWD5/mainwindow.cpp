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

int MainWindow::random_number() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 99);
    return dist(mt);
}

void MainWindow::pain()
{
    QString str1(""), str2("");
    for(int i = 0; i < ueue.getSize(); ++i)
    {
         str1 +=QString::number(ueue[i]) + " ";
    }
    for(int i = 0; i < deue.size(); ++i)
    {
         str2 +=QString::number(deue[i]) + " ";
    }
    ui->textEdit->setText(str1);
    ui->textEdit_2->setText(str2);
}

void MainWindow::on_pushButton_clicked()
{
    QString str1(""), str2("");
        for (int i = 0; i < 10; i++) {
            ueue.push(random_number());
            deue.push_back(random_number());
           }
        pain();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString s1, s2, s3, s4, s5, s6;
    ueue.cycle(s1, s2, s3, s4, s5, s6);
    ui->lineEdit_3->setText(s1);
    ui->lineEdit_4->setText(s2);
    ui->lineEdit_5->setText(s3);
    ui->lineEdit_6->setText(s4);
    ui->lineEdit_7->setText(s5);
    ui->lineEdit_8->setText(s6);
}


void MainWindow::on_pushButton_3_clicked()
{
    int a = ui->lineEdit_9->text().toInt();
    deue.push_back(a);
    ueue.push(a);
    pain();
}


void MainWindow::on_pushButton_4_clicked()
{
    int a = ui->lineEdit_9->text().toInt();
    deue.push_front(a);
    pain();
}


void MainWindow::on_pushButton_5_clicked()
{
    int a =ueue.pop(), b = deue.pop_back();
    ui->lineEdit_11->setText(QString::number(a));
    ui->lineEdit->setText(QString::number(b));
    pain();
}



void MainWindow::on_pushButton_6_clicked()
{
    int a = deue.pop_front();
    ui->lineEdit_12->setText(QString::number(a));
    pain();
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit_13->setText(QString::number(ueue.getSize()));
    ui->lineEdit_2->setText(QString::number(deue.size()));
}


void MainWindow::on_pushButton_9_clicked()
{
    ueue.clear();
    deue.clear();
    pain();
}


void MainWindow::on_pushButton_8_clicked()
{
    if (ueue.isEmpty())
        ui->lineEdit_14->setText("Yes");
    else
        ui->lineEdit_14->setText("No");

    if (deue.empty())
        ui->lineEdit_15->setText("Yes");
    else
        ui->lineEdit_15->setText("No");

}

