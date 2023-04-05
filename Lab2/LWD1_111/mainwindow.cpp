#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::setStyleSheet("QMainWindow { background-color: #b3e5fc; }");
    ui->label_7->setStyleSheet("background-image: url(\"C:/C++/Labs/Lab2/LWD1_1/Sourse/pl.png\"); background-repeat: no-repeat; background-position: center;");
    ui->label_8->setStyleSheet("background-color: #eff9fe; border-radius: 10px;");
    ui->label_9->setStyleSheet("background-color: #eff9fe; border-radius: 10px;");
    ui->label_4->setStyleSheet("color: #141b1f");
    ui->label_3->setStyleSheet("color: #141b1f");
    ui->label_2->setStyleSheet("color: #141b1f");
    ui->label_6->setStyleSheet("color: #141b1f");
    ui->label_5->setStyleSheet("color: #141b1f");
    ui->label->setStyleSheet("color: #4a6d91");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->lineEdit_4->setPlaceholderText("Введите номер рейса");
    ui->lineEdit_5->setPlaceholderText("Введите время вылета");
    ui->lineEdit_6->setPlaceholderText("Введите модель самолёта");
    ui->lineEdit_7->setPlaceholderText("Введите пункт назначения");

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
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(timeTable[i].getTime()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(timeTable[i].getModel()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(timeTable[i].getDestination()));
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
    List TT;
    timeTable = TT;
    timeTable.clear();
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
                QMessageBox::warning(Q_NULLPTR,"Warning", "Файл содержит некорректные данные!");
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
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Сначала откройте файл с расписанием!");
        return;
    }
    QFile file (fileName);
    if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is successfully open!\n";
        QTextStream ptr(&file);
        ptr.seek(-1);

        Flight temp;

        if (ui->lineEdit_4->text() == "" || ui->lineEdit_5->text() == "" || ui->lineEdit_6->text() == "" || ui->lineEdit_7->text() == "")
        {
            QMessageBox::warning(Q_NULLPTR,"Warning", "Форма заполнена некорректно!");
            return;
        }

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
            QMessageBox::warning(Q_NULLPTR,"Warning", "Форма заполнена некорректно!");
            clearTable();
            updateTable();
            return;
        }
    }
    else
    {
        qDebug() << "File isn't open!\n";
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Сначала откройте файл с расписанием!");
        return;
    }
    QFile file (fileName);
    if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is successfully open!\n";
        QTextStream ptr(&file);
         ptr.seek(0);
         QString str;
         str =ui->lineEdit_8->text();
         bool ex = false;
         for (int i = 0; i < timeTable.getSize(); i++)
         {
             if (timeTable[i].getNumber() == str)
             {
                 ex = true;
                 break;
             }
         }
         if(!ex)
         {
            QMessageBox::warning(Q_NULLPTR,"Warning", "Указанного рейса не существует!");
            return;
         }
         else
         {
            timeTable.cut_out(str);
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
                clearTable();
                updateTable();
                return;
            }
            ptr.seek(0);
            int count = 0;
             while(!ptr.atEnd())
             {
                  ++count;
                 QString tp = ptr.readLine();
                 if((count != imposter) && (count != imposter + 1) && (count != imposter + 2) && (count != imposter + 3))
                 {
                     newFile += tp + "\n";
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
              for(int i = 0; i < timeTable.getSize(); i++)
              {
                  qDebug() << timeTable[i].getNumber()<<'\n';
                  qDebug() << timeTable[i].getTime()<<'\n';
                  qDebug() << timeTable[i].getModel()<<'\n';
                  qDebug() << timeTable[i].getDestination()<<'\n';
              }

         }
    }
    else
    {
        qDebug() << "File isn't open!\n";
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Сначала откройте файл с расписанием!");
        return;
    }
    clearTable();
    int rowsNumber = 0;
    QString str;
    str =ui->lineEdit_3->text();
    bool check = 0;
    for (int i = 0; i < timeTable.getSize(); i++)
    {

        if (str == timeTable[i].getNumber())
        {
            check = 1;
            rowsNumber++;
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(rowsNumber - 1, 0, new QTableWidgetItem(timeTable[i].getNumber()));
            ui->tableWidget->setItem(rowsNumber - 1, 1, new QTableWidgetItem(timeTable[i].getTime()));
            ui->tableWidget->setItem(rowsNumber - 1, 2, new QTableWidgetItem(timeTable[i].getModel()));
            ui->tableWidget->setItem(rowsNumber - 1, 3, new QTableWidgetItem(timeTable[i].getDestination()));
        }
    }
    if (!check)
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Рейсов по данному параметру не найдено!");
        clearTable();
        updateTable();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Сначала откройте файл с расписанием!");
        return;
    }
    clearTable();
    int rowsNumber = 0;
    QString str;
    str =ui->lineEdit_2->text();
     bool check = 0;
    for (int i = 0; i < timeTable.getSize(); i++)
    {

        if (str == timeTable[i].getDestination())
        {
            check = 1;
            rowsNumber++;
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(rowsNumber - 1, 0, new QTableWidgetItem(timeTable[i].getNumber()));
            ui->tableWidget->setItem(rowsNumber - 1, 1, new QTableWidgetItem(timeTable[i].getTime()));
            ui->tableWidget->setItem(rowsNumber - 1, 2, new QTableWidgetItem(timeTable[i].getModel()));
            ui->tableWidget->setItem(rowsNumber - 1, 3, new QTableWidgetItem(timeTable[i].getDestination()));
        }
    }
    if (!check)
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Рейсов по данному параметру не найдено!");
        clearTable();
        updateTable();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Сначала откройте файл с расписанием!");
        return;
    }
    clearTable();
    int rowsNumber = 0;
    QString str;
    str =ui->lineEdit->text();
     bool check = 0;
    QTime tim = QTime::fromString(str, "hh:mm");
    if(tim.isValid())
    {
    for (int i = 0; i < timeTable.getSize(); i++)
    {
        QString amogus = timeTable[i].getTime();
        qDebug() <<  amogus;

        if (str == timeTable[i].getTime())
        {
            check = 1;
            rowsNumber++;
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(rowsNumber - 1, 0, new QTableWidgetItem(timeTable[i].getNumber()));
            ui->tableWidget->setItem(rowsNumber - 1, 1, new QTableWidgetItem(timeTable[i].getTime()));
            ui->tableWidget->setItem(rowsNumber - 1, 2, new QTableWidgetItem(timeTable[i].getModel()));
            ui->tableWidget->setItem(rowsNumber - 1, 3, new QTableWidgetItem(timeTable[i].getDestination()));
        }
    }
    }
    else
    {
         QMessageBox::warning(Q_NULLPTR,"Warning!", "Введенное значение времени некорректно!");
         clearTable();
         updateTable();
         return;
    }
    if (!check)
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Рейсов по данному параметру не найдено!");
        clearTable();
        updateTable();
    }
}

