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


void MainWindow::updateTable(int numRows)
{
    ui->tableWidget->setRowCount(numRows);

    for (int i = 0; i < AllTheDates.size(); i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(AllTheDates[i].getfullDate()));
    }
}

void MainWindow::on_pushButton_clicked()
{
 Date::openFile();
 MainWindow::updateTable(AllTheDates.size());

}

void MainWindow::on_pushButton_7_clicked()
{
    for (int i = 0; i < AllTheDates.size(); i++)
    {

       ui->tableWidget->setItem(i, 1, new QTableWidgetItem(AllTheDates[i].NextDay().getfullDate()));

    }
}


void MainWindow::on_pushButton_8_clicked()
{
    for (int i = 0; i < AllTheDates.size(); i++)
    {

       ui->tableWidget->setItem(i, 2, new QTableWidgetItem(AllTheDates[i].PreviousDay().getfullDate()));

    }
}


void MainWindow::on_pushButton_9_clicked()
{
    for (int i = 0; i < AllTheDates.size(); i++)
    {
        if(AllTheDates[i].IsLeap())
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("Yes"));
        else
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("No"));
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    for (int i = 0; i < AllTheDates.size(); i++)
    {
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(AllTheDates[i].WeekNumber())));
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit->text();
    if(str == "")
    {
        QMessageBox::warning(this,"Warning", "Enter the birthday date!");
    }
    else if(Date::getFileName() == "")
    {
         QMessageBox::warning(this,"Warning", "Open the file first!");
    }
    else
    {
    qDebug() << str;
    QDate temp = QDate::fromString(str, "dd.MM.yyyy");
    if(temp.isValid())
    {
         AllTheDates[0].setBirthDay(str);
    }
    else
        QMessageBox::warning(this, "Warning", "The entered date is incorrect!");
    }

}


void MainWindow::on_pushButton_11_clicked()
{
    QString str = ui->lineEdit->text();
    if(str == "")
    {
        QMessageBox::warning(this,"Warning", "Enter the birthday date!");
    }
    else if(Date::getFileName() == "")
    {
         QMessageBox::warning(this,"Warning", "Open the file first!");
    }
    else
    {
    for (int i = 0; i < AllTheDates.size(); i++)
        {
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(AllTheDates[i].DaysTillYourBithday())));
        }
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    for (int i = 0; i < AllTheDates.size(); i++)
        {
            ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(AllTheDates[i].Duration())));
        }

}


void MainWindow::on_pushButton_3_clicked()
{
    if(Date::getFileName() == "")
    {
         QMessageBox::warning(Q_NULLPTR,"Warning", "Open the file first!");
    }
    else
    {
    QString str = ui->lineEdit_2->text();
    Date::addNewDate(str);
    ui->tableWidget->setRowCount(AllTheDates.size());
    ui->tableWidget->setItem(AllTheDates.size() - 1, 0, new QTableWidgetItem(AllTheDates[AllTheDates.size() - 1].getfullDate()));
    }
}


void MainWindow::on_pushButton_5_clicked()
{
     QString str = ui->lineEdit_5->text();
      Date::deleteDate(str);
      ui->tableWidget->setRowCount(AllTheDates.size());
      for (int i = 0; i < AllTheDates.size(); i++)
      {
          ui->tableWidget->setItem(i, 0, new QTableWidgetItem(AllTheDates[i].getfullDate()));
      }

}


void MainWindow::on_pushButton_4_clicked()
{
    QString from = ui->lineEdit_3->text();
    QString to = ui->lineEdit_4->text();
    Date::reverse(from, to);
    for (int i = 0; i < AllTheDates.size(); i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(AllTheDates[i].getfullDate()));
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    Date::fullDelete();
    ui->tableWidget->setRowCount(0);
}

