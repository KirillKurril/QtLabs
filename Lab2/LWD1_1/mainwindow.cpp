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


void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(timeTable.getSize());
    qDebug() << timeTable.getSize();
    for (int i = 0; i < timeTable.getSize(); i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(timeTable[i].getNumber()));
         qDebug() << timeTable[i].getNumber();
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(timeTable[i].getTime()));
         qDebug() << timeTable[i].getTime();
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(timeTable[i].getModel()));
         qDebug() << timeTable[i].getModel();
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(timeTable[i].getDestination()));
         qDebug() << timeTable[i].getDestination();
    }
}

void MainWindow::clearTable()
{
    ui->tableWidget->setRowCount(0);
}

void MainWindow::on_pushButton_clicked()
{
    open_file(timeTable, fileName);
    updateTable();
}

void MainWindow::open_file(List &timeTable, QString& fileName)
{
        fileName = QFileDialog::getOpenFileName();
        QFile file (fileName);
        if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
        {
            qDebug() << "File is successfully open!\n";
        QTextStream counter(&file);
        counter.seek(0);
        int i = 0;
        while(!counter.atEnd())
        {
            Flight temp;
            QString str;
            str = counter.readLine();

            temp.setNumber(str);
            str = counter.readLine();

            QTime tim = QTime::fromString(str, "hh:mm");
            if(tim.isValid())
            {
            temp.setTime(str);
            str = counter.readLine();

            temp.setModel(str);
            str = counter.readLine();

            temp.setDestination(str);

            timeTable.add(temp);




            i++;
            }

            else
            {
                QMessageBox::warning(Q_NULLPTR,"Warning", "File containes incorrect data!");
                break;
            }
        }
        file.close();
        }
        else
        {
            qDebug() << "File isn't open!\n";
        }
}

void MainWindow::on_pushButton_5_clicked()
{
    QFile file (fileName);
    if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is successfully open!\n";
        QTextStream ptr(&file);
        ptr.seek(-1);

        Flight temp;
        QString str;
        str =ui->lineEdit_4->text();
        temp.setNumber(str);
        ptr << str << '\n';
        str =ui->lineEdit_5->text();
        QTime tim = QTime::fromString(str, "hh:mm");
        if(tim.isValid())
        {
        temp.setTime(str);
        ptr << str << '\n';
        str =ui->lineEdit_6->text();
        temp.setModel(str);
        ptr << str << '\n';
        str =ui->lineEdit_7->text();
        temp.setDestination(str);
        ptr << str << '\n';

        timeTable.add(temp);
        updateTable();
        file.close();
        }
        else
        {
            QMessageBox::warning(Q_NULLPTR,"Warning", "File containes incorrect data!");
        }
    }
    else
    {
        qDebug() << "File isn't open!\n";
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    QFile file (fileName);
    if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is successfully open!\n";
        QTextStream ptr(&file);
         ptr.seek(0);
         QString str;
         str =ui->lineEdit_8->text();
         if(!timeTable.cut_out(str))
         {
            QMessageBox::warning(Q_NULLPTR,"Warning", "Указанного рейса не существует!");
         }
         else
         {
            clearTable();
            updateTable();
            ptr.seek(0);
            QString newFile;
            int lines = 0, imposter = -1;
            while(!ptr.atEnd())
            {
                 QString tp = ptr.readLine();
                 lines++;
                 if(tp == str)
                    imposter = lines;



            }
            if (imposter == -1)
            {
                QMessageBox::warning(Q_NULLPTR,"Warning", "Указанного рейса не существует!");
            }
            ptr.seek(0);
            int count = 0;
             while(!ptr.atEnd())
             {
                 QString tp = ptr.readLine();
                 if((count != imposter) && (count != imposter + 1) && (count != imposter + 2) && (count != imposter + 3))
                 {
                     newFile += tp + "\n";
                     count++;
                 }
             }
            file.close();
             QFile file (fileName);
             if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
             {
                 qDebug() << "File is successfully open!\n";
             }
             else
             {
                 qDebug() << "File isn't open!\n";
             }
             QTextStream fout (&file);
             fout << newFile;
              file.close();

         }
    }
    else
    {
        qDebug() << "File isn't open!\n";
    }
}

