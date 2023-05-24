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



void MainWindow::on_open_file_button_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,"Выберите файл","D:/Qt/Projects/"," .h файлы (*h),.cpp файлы(*cpp)");
    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream out(&file);
    text=out.readAll();
    ui->plainTextEdit->setPlainText(text);
}

void MainWindow::on_vars_button_clicked()
{
    text=ui->plainTextEdit->toPlainText();
    QMessageBox::information(this,"Vars",Parser::parseVars(text));
}

void MainWindow::on_structs_button_clicked()
{
    text=ui->plainTextEdit->toPlainText();
    QMessageBox::information(this,"Structs",Parser::parseStructs(text));
}

void MainWindow::on_prototypes_button_clicked()
{
    text=ui->plainTextEdit->toPlainText();
    QMessageBox::information(this,"Prototypes",Parser::parsePrototypes(text));
}

void MainWindow::on_changes_button_clicked()
{
    text=ui->plainTextEdit->toPlainText();
    QMessageBox::information(this,"Changes",Parser::parseChanges(text));
}


void MainWindow::on_local_vars_clicked()
{
    text=ui->plainTextEdit->toPlainText();
    QMessageBox::information(this,"Local_vars",Parser::parseLocalVars(text));
}



void MainWindow::on_overloads_button_clicked()
{
    text=ui->plainTextEdit->toPlainText();
    QMessageBox::information(this,"Overloads",Parser::parseOverloads(text));
}


void MainWindow::on_depth_button_clicked()
{
    text=ui->plainTextEdit->toPlainText();
    QMessageBox::information(this,"Deapth of branches",Parser::parseDepth(text));
}


void MainWindow::on_logic_button_clicked()
{
    text=ui->plainTextEdit->toPlainText();
    QMessageBox::information(this,"Logical Errors",Parser::parseLogic(text));
}

