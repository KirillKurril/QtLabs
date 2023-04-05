#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spellcheck.h"
QString MainWindow::fileName;

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


void MainWindow::on_pushButton_clicked()
{
    fileName = QFileDialog::getOpenFileName();
}


void MainWindow::on_pushButton_2_clicked()
{
    if (fileName == "")
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Open the file first!");
        return;
    }
    QFile file (fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "File isn't open!");
    }
    else
    {
        qDebug() << "File is successfully open!\n";
    QTextStream counter(&file);
    counter.seek(0);
    QString str = file.readAll();
    SpellCheck* stack = new SpellCheck;
    int rows = 1, numbers = 0;
    for(int i = 0; i < str.size(); i++)
    {
        QChar tp = str[i];
        if(tp == '\n')
        {
            ++rows;
            numbers = 0;
        }
        else
        {
            ++numbers;
        }

        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            stack->push(i, numbers, rows);

        } else if(str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            if(stack->isEmpty())
            {
                QMessageBox::warning(Q_NULLPTR,"Warning", "Incorrect placement of brackets at position\nrow: " + QString::number(rows) + "\nposition: " + QString::number(numbers));
                return;
            }
        QChar last = str[stack->top()];
        if ((last == '[' && tp != ']') || (last == '{' && tp != '}') || (last == '(' && tp != ')'))
        {
            QMessageBox::warning(Q_NULLPTR,"Warning", "Incorrect placement of brackets at position\nrow: " + QString::number(rows) + "\nposition: " + QString::number(numbers));
            return;
        }
        stack->pop();
        }

    }
    if (stack->isEmpty())
    {
         QMessageBox::information(Q_NULLPTR,"Warning", "Success!");
    }
    else
    {
        QMessageBox::warning(Q_NULLPTR,"Warning", "Incorrect placement of brackets at position\nrow: " + QString::number(stack->getRowss()) + "\nposition: " + QString::number(stack->getNums()));
    }
    file.close();
}
}

