#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "masslist.h"
QString MainWindow::fileName;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QIcon icon("C:/C++/Labs/Lab2/LWD1_2/images/icon.png");
    window()->setWindowIcon(icon);
    QMainWindow::setStyleSheet("QMainWindow { background-color: #7c534d; }");
    ui->label_2->setStyleSheet("background-image: url(\"C:/C++/Labs/Lab2/LWD1_2/images/back.png\"); background-repeat: no-repeat; background-position: center;");
    ui->back1->setStyleSheet("background-color: rgba(159,169,255,0.5); border-radius: 10px;");
    ui->back2->setStyleSheet("background-color: rgba(159,169,255,0.5); border-radius: 10px;");
    ui->tableWidget->setStyleSheet("background-color: rgba(159,169,255,0.5); border-radius: 10px;");
    ui->label->setStyleSheet("color: white;");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete list;
    delete exList;
    delete unexList;
}

void MainWindow::updateTable(MassList* putlist)
{
    ui->tableWidget->setRowCount(putlist->getSize());
    for (int i = 0; i < putlist->getSize(); i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(putlist->arr[i]->getNumber()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(putlist->arr[i]->getStart_time()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(putlist->arr[i]->getFinish_time()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(putlist->arr[i]->getModel()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(putlist->arr[i]->getDestination()));
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    list = new MassList;
    exList = new MassList;
    unexList = new MassList;
     MassList* tplist = new MassList;
     list = tplist;
     ui->tableWidget->setRowCount(0);
     fileName = QFileDialog::getOpenFileName();
     QFile file (fileName);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
         QMessageBox::warning(Q_NULLPTR,"Warning", "Не удалось открыть файл!");
     }
     else
     {
         qDebug() << "File is successfully open!\n";
     QTextStream counter(&file);
     counter.seek(0);
     QString str;
     QTime current = QTime::currentTime();
     while(!counter.atEnd())
     {
        Abobus* temp = new Abobus;
        str = counter.readLine();
        temp->setNumber(str);
        str = counter.readLine();
        QTime stime = QTime::fromString(str, "hh:mm");
        if(stime.isValid())
        {
            temp->setStart_time(str);
            str = counter.readLine();
            QTime etime = QTime::fromString(str, "hh:mm");
            if(etime.isValid())
            {
                temp->setFinish_time(str);
                str = counter.readLine();
                 temp->setModel(str);
                str = counter.readLine();
                 temp->setDestination(str);
                 list->add(temp);
                 if (current > stime && current <= etime)
                 unexList->add(temp);
                 else
                 exList->add(temp);
            }
            else
            {
                QMessageBox::warning(Q_NULLPTR,"Warning", "Файл содержит некорректные данные!");
                break;
            }


        }
        else
        {
            QMessageBox::warning(Q_NULLPTR,"Warning", "Файл содержит некорректные данные!");
            break;
        }


     }

}
}


void MainWindow::on_pushButton_clicked()
{
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Сначала откройте файл с расписанием!");
        return;
    }
    updateTable(list);
}


void MainWindow::on_pushButton_8_clicked()
{
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Сначала откройте файл с расписанием!");
        return;
    }
    updateTable(unexList);
}


void MainWindow::on_pushButton_7_clicked()
{
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Сначала откройте файл с расписанием!");
        return;
    }
    updateTable(exList);
}


void MainWindow::on_pushButton_4_clicked()
{
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Сначала откройте файл с расписанием!");
        return;
    }
    QString str = ui->lineEdit_3->text();
    QTime etime = QTime::fromString(str, "hh:mm");
    if(etime.isValid())
    {
        int counter = 0;
        for (int i = 0; i < list->getSize(); i++)
        {
            if (QTime::fromString(list->arr[i]->getFinish_time(), "hh:mm") < etime)
                counter++;
        }
    ui->tableWidget->setRowCount(counter);
    counter = 0;
    for (int i = 0; i < list->getSize(); i++)
    {
         if (QTime::fromString(list->arr[i]->getFinish_time(), "hh:mm") < etime)
        {
            ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(list->arr[i]->getNumber()));
            ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(list->arr[i]->getStart_time()));
            ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(list->arr[i]->getFinish_time()));
            ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(list->arr[i]->getModel()));
            ui->tableWidget->setItem(counter, 4, new QTableWidgetItem(list->arr[i]->getDestination()));
            counter++;
        }
    }
    }
    else
    {
         QMessageBox::warning(Q_NULLPTR,"Warning", "Вы ввели некорректное время!\nВведите время в формате чч:мм");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Сначала откройте файл с расписанием!");
        return;
    }
    QString str = ui->lineEdit_2->text();
    int counter = 0;
    for (int i = 0; i < list->getSize(); i++)
    {
        if (list->arr[i]->getDestination() == str)
            counter++;
    }
    if (counter == 0)
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Маршрутов по данному пункту назначения не найдено!");
        return;
    }
    ui->tableWidget->setRowCount(counter);
    counter = 0;
    for (int i = 0; i < list->getSize(); i++)
    {
            if (list->arr[i]->getDestination() == str)
        {
            ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(list->arr[i]->getNumber()));
            ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(list->arr[i]->getStart_time()));
            ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(list->arr[i]->getFinish_time()));
            ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(list->arr[i]->getModel()));
            ui->tableWidget->setItem(counter, 4, new QTableWidgetItem(list->arr[i]->getDestination()));
            counter++;
        }
    }
}

