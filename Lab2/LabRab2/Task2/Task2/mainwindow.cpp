#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setReadOnly(0);
    isFileOpen = 0;
    line = "";
    row = 1;
    col = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openFileButton_clicked()
{
    QString backup = fileAdress;
    fileAdress = QFileDialog::getOpenFileName(this, "Открыть файл", "C:/Users/dzmitry/source/repos/2semestr/LabRab2/Task2/Task2", "Text files (*.txt);; CPP files (*.cpp)");
    QFile file(fileAdress);
    file.open(QIODevice::ReadWrite);
    if(file.size() == 0){
        QMessageBox::critical(this, "Ошибка.", "Файл пуст.");
        fileAdress = backup;
        return;
    }
    line.clear();
    while(!file.atEnd()){
        line += file.readLine();
    }
    ui->textBrowser->setText(line);
    isFileOpen = 1;
    file.close();
}

bool MainWindow::is_valid(QString s, int &row, int &col) {
    MyStack stack;
    std::string str = s.toStdString();
    for (char c : str) {
        ++col;
        if(c == '\n'){
            ++row;
            col = 0;
        }
        switch (c) {
        case '(':
        case '{':
        case '[':
            stack.push(c, row, col);
            break;
        case ')':
            if (stack.isEmpty() || stack.topElement()->bracket != '(') {
                while(!stack.isEmpty()){
                    Node* temp = new Node;
                    temp = stack.pop();
                    row = temp->row;
                    col = temp->col;
                }
                return false;
            }
            stack.pop();
            break;
        case '}':
            if (stack.isEmpty() || stack.topElement()->bracket != '{') {
                while(!stack.isEmpty()){
                    Node* temp = new Node;
                    temp = stack.pop();
                    row = temp->row;
                    col = temp->col;
                }
                return false;
            }
            stack.pop();
            break;
        case ']':
            if (stack.isEmpty() || stack.topElement()->bracket != '[') {
                while(!stack.isEmpty()){
                    Node* temp = new Node;
                    temp = stack.pop();
                    row = temp->row;
                    col = temp->col;
                }
                return false;
            }
            stack.pop();
            break;
        default:
            break;
        }
    }
    bool vadim = stack.isEmpty();
    while(!stack.isEmpty()){
        Node* temp = new Node;
        temp = stack.pop();
        row = temp->row;
        col = temp->col;
    }
    return vadim;
}

void MainWindow::on_checkCodeButton_clicked()
{
    line = ui->textBrowser->toPlainText();
    if(!is_valid(line, row, col)) QMessageBox::critical(this, "Статус кода.", "Код некорректен. Ошибка в строке: " + QString::number(row) + ", в столбце: " + QString::number(col));
    else QMessageBox::information(this, "Статус кода.", "Код корректен.");
    row = 1;
    col = 0;
}
