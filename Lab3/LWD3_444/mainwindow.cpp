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
            str += QString::number(vec1[i]) + ' ';
        }
    ui->textEdit->setText(str);
}

void MainWindow::print2()
{
    QString str = "";
    for (int i = 0; i < vec2.size(); ++i)
        {
            str += QString::number(vec2[i]) + ' ';
        }
    ui->textEdit_2->setText(str);
}

void MainWindow::achtung()
{
    QMessageBox::warning(this, "Внимание!", "Проверьте корректность введённых данных!");
}


void MainWindow::on_pushButton_clicked()
{
    vec1.clear();
    size_t size = std::rand() % 6 + 5;
    //DVector<int> vec1;
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
    vec2.clear();
    size_t size = std::rand() % 6 + 5;
     //DVector<int> vec2;
    vec2.resize(size);
    QString str = "";
    for (int i = 0; i < size; ++i)
        {
            vec2.push_back(std::rand() % 99 + 1);
            str += QString::number(vec2[i]) + ' ';
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
    print1();
    print2();
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
    if(!(ui->lineEdit_7->text().toInt() && ui->lineEdit_8->text().toInt()))
    {
        achtung();
        return;
    }
    vec1.assign(ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt());
    print1();
    print2();
}


void MainWindow::on_erase_button_clicked()
{
    if(!(ui->lineEdit_6->text().toInt() && ui->lineEdit_6->text().toInt()))
    {
        achtung();
        return;
    }
    vec1.erase(ui->lineEdit_6->text().toInt());
    vec2.erase(ui->lineEdit_6->text().toInt());
    print1();
    print2();
}


void MainWindow::on_capacity_button_clicked()
{
    ui->textEdit_5->setText(QString::number(vec1.capacity()) + '\n' + QString::number(vec2.capacity()));
}


void MainWindow::on_push_back_button_clicked()
{
    if(!ui->lineEdit_5->text().toInt())
    {
        achtung();
        return;
    }
    vec1.push_back(ui->lineEdit_5->text().toInt());
    vec2.push_back(ui->lineEdit_5->text().toInt());
    print1();
    print2();
}


void MainWindow::on_size_button_clicked()
{
    ui->textEdit_6->setText(QString::number(vec1.size()) + '\n' + QString::number(vec2.size()));
}


void MainWindow::on_clear_button_clicked()
{
    vec1.clear();
    vec2.clear();
    print1();
    print2();
}


void MainWindow::on_empty_button_clicked()
{
    QString str = "";
     if (vec1.empty()) str += "vec 1 is empty";
     else str += "vec 1 isn't empty";
     str += "\n";
     if (vec2.empty()) str += ("vec 2 is empty");
     else str += ("vec 2 isn't empty");
     ui->textEdit_4->setText(str);
}


void MainWindow::on_insert_button_clicked()
{
    if(!(ui->lineEdit_3->text().toInt() && ui->lineEdit_4->text().toInt()))
    {
        achtung();
        return;
    }
    vec1.insert(ui->lineEdit_3->text().toInt(), ui->lineEdit_4->text().toInt());
    print1();
}


void MainWindow::on_emplace_button_clicked()
{
    if(!(ui->lineEdit_9->text().toInt() && ui->lineEdit_2->text().toInt()))
    {
        achtung();
        return;
    }
    vec1.emplace(ui->lineEdit_9->text().toInt(), ui->lineEdit_2->text().toInt());
    print1();
}


void MainWindow::on_emplace_back_button_clicked()
{
    if(!ui->lineEdit->text().toInt())
    {
        achtung();
        return;
    }
    vec1.emplace_back(ui->lineEdit->text().toInt());
    print1();
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{

}

