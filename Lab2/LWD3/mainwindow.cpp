#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RowsComp = new tableComponent[256];
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
    for(int i = 0; !counter.atEnd(); i++)
    {
        ++rows_counter;
         ui->tableWidget->setRowCount(rows_counter + 1);
         str = counter.readLine();
         RowsComp[++columnsCounter].setExpression(str);
         ui->tableWidget->setItem(i, 0, new QTableWidgetItem(str));
         str = counter.readLine();
         RowsComp[columnsCounter].setA(str.toDouble());
         ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str));
         str = counter.readLine();
         RowsComp[columnsCounter].setB(str.toDouble());
         ui->tableWidget->setItem(i, 2, new QTableWidgetItem(str));
         str = counter.readLine();
         RowsComp[columnsCounter].setC(str.toDouble());
         ui->tableWidget->setItem(i, 3, new QTableWidgetItem(str));
         str = counter.readLine();
         RowsComp[columnsCounter].setD(str.toDouble());
         ui->tableWidget->setItem(i, 4, new QTableWidgetItem(str));
         str = counter.readLine();
         RowsComp[columnsCounter].setE(str.toDouble());
         ui->tableWidget->setItem(i, 5, new QTableWidgetItem(str));
    }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->setRowCount(++columnsCounter);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString pup;
    RPN* processor = new RPN;
    for(int i = 0; i <= rows_counter; i++)
       {
        pup = processor->process(RowsComp[i]);
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(pup));
        qDebug() << pup;
        processor = new RPN;
       }

}

