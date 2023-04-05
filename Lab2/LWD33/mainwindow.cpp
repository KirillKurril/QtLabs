#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->variableEditA->setValue(1);
//    ui->variableEditB->setValue(1);
//    ui->variableEditC->setValue(1);
//    ui->variableEditD->setValue(1);
//    ui->variableEditE->setValue(1);
    QIcon icon("C:/C++/Labs/Lab2/LWD33/Poland.png");
    ui->kit->setStyleSheet("background-image: url(\"C:/C++/Labs/Lab2/LWD33/kit.png\"); background-repeat: no-repeat; background-position: center; border-radius: 60%;");
    window()->setWindowIcon(icon);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::is_valid(QString s) {
    MyStack stack;
    std::string str = s.toStdString();
    for (char c : str) {
        switch (c) {
        case '(':
        case '{':
        case '[':
            stack.push(c);
            break;
        case ')':
            if (stack.isEmpty() || stack.topElement()->element != '(') {
                while(!stack.isEmpty()){
                    Node* temp = new Node;
                    temp = stack.pop();
                }
                return false;
            }
            stack.pop();
            break;
        case '}':
            if (stack.isEmpty() || stack.topElement()->element != '{') {
                while(!stack.isEmpty()){
                    Node* temp = new Node;
                    temp = stack.pop();
                }
                return false;
            }
            stack.pop();
            break;
        case ']':
            if (stack.isEmpty() || stack.topElement()->element != '[') {
                while(!stack.isEmpty()){
                    Node* temp = new Node;
                    temp = stack.pop();
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
    }
    return vadim;
}


void MainWindow::on_evaluate2_clicked()
{
    if(ui->formulaEdit->text().isEmpty()){
        QMessageBox::critical(this, "Ошибка", "Сначала введите выражение!.");
        return;
    }
    QString line = ui->formulaEdit->text();
    std::string str = "abcde/*-+()";
    std::string var = "abcde";
    bool isThereLetter = 0;
    for(int i = 0; i < line.size(); ++i){
        if(((i == 0) || (i == line.size() - 1)) && ((line[i] == '+') || (line[i] == '-') || (line[i] == '*') || (line[i] == '/'))){
            QMessageBox::critical(this, "Ошибка", "Некорректная формула.");
            return;
        }
        if(((line[i] == '+') || (line[i] == '-') || (line[i] == '*') || (line[i] == '/')) && isThereLetter == 0){
            QMessageBox::critical(this, "Ошибка", "Некорректная формула.");
            return;
        }
        if(i){
            if ((line[i] == line[i - 1]) && (line[i] != '(') && (line[i] != ')'))
            {
                    QMessageBox::critical(this, "Ошибка", "Некорректная формула.");
                    return;
            }
            if ((var.find(line[i].toLatin1(), 0) != std::string::npos) && (var.find(line[i - 1].toLatin1(), 0) != std::string::npos)){
                QMessageBox::critical(this, "Ошибка", "Некорректная формула.");
                return;
            }
        }

        if(line[i] == ' '){
            QMessageBox::critical(this, "Ошибка", "Введите формулу без пробелов.");
            return;
        }
        if(str.find(line[i].toLatin1(), 0) == std::string::npos){
            QMessageBox::critical(this, "Ошибка", "Некорректная формула. Используйте символы: a b c d e ( ) + - * /");
            return;
        }
        if(line[i] == 'a' || line[i] == 'b' || line[i] == 'c' || line[i] == 'd' || line[i] == 'e') isThereLetter = 1;
    }
    if(!isThereLetter){
        QMessageBox::critical(this, "Ошибка", "Отсутствуют переменные.");
        return;
    }
    if(!is_valid(line)){
        QMessageBox::critical(this, "Ошибка", "Некорректная формула.");
        return;
    }
    else{
        answer = OPZ(line);
//        try {
//            evaluation(answer);
//            ui->textBrowser->setText("Ответ: " + QString::number(evaluation(answer)) + "\nОПЗ: " + answer);
//        } catch (const char* msg) {
//            QMessageBox::critical(this, "Ошибка.", "Деление на ноль.");
//            return;
//        }

        try {
            double value;
           if( evaluation(answer, value))
            ui->textBrowser->setText("Ответ: " + QString::number(value) + "\nОПЗ: " + answer);
           else
               return;
        } catch (const char* msg) {
            QMessageBox::critical(this, "Ошибка.", "Деление на ноль.");
        }
    }
}

int getPriority(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

QString MainWindow::OPZ(QString line)
{
    MyStack operation;
    QString opz = "";
    std::string str = line.toStdString();
    Node* temp = new Node;
    for(int i = 0; i < line.size(); ++i){

        if(str[i] == '('){
            operation.push(str[i]);
        }


        else if(str[i] == ')'){
            temp = operation.pop();
            while(temp->element != '('){
                opz += temp->element;
                temp = operation.pop();
            }
        }


        else if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/')){
            if(!operation.isEmpty()){
                temp = operation.topElement();
                while ((temp->element != '(')
                       && !operation.isEmpty()
                       && (getPriority(str[i]) <= getPriority(temp->element)))
                {
                        temp = operation.pop();
                        opz += temp->element;
                        temp = operation.topElement();
                        if(operation.isEmpty()) break;
                }
            }
            operation.push(str[i]);
        }

        else{
            opz += str[i];
        }
    }
    while(!operation.isEmpty()){
        temp = operation.pop();
        opz += temp->element;
    }
    return opz;
}

bool MainWindow::evaluation(QString line, double& value)
{
    bool boobl;
    ui->lineEditA->text().toDouble(&boobl);
    if (boobl)
    {
        A = ui->lineEditA->text().toDouble();
    }
    else
    {
         QMessageBox::critical(this, "Ошибка!", "Измените значение переменной а");
        //QMessageBox::critical(this, "( ͡° ͜ʖ ͡ -)", "А ты шалун!\nБудь лапочкой, поменяй значение переменной а");
        return false;
    }
    ui->lineEditB->text().toDouble(&boobl);
    if (boobl)
    {
        B = ui->lineEditB->text().toDouble();
    }
    else
    {
        QMessageBox::critical(this, "Ошибка!", "Измените значение переменной b");
        //QMessageBox::critical(this, "( ͡° ͜ʖ ͡ -)", "А ты шалун!\nБудь лапочкой, поменяй значение переменной b");
        return false;
    }
    ui->lineEditC->text().toDouble(&boobl);
    if (boobl)
    {
        C = ui->lineEditC->text().toDouble();
    }
    else
    {
        QMessageBox::critical(this, "Ошибка!", "Измените значение переменной c");
        //QMessageBox::critical(this, "( ͡° ͜ʖ ͡ -)", "А ты шалун!\nБудь лапочкой, поменяй значение переменной c");
        return false;
    }
    ui->lineEditD->text().toDouble(&boobl);
    if (boobl)
    {
        D = ui->lineEditD->text().toDouble();
    }
    else
    {
        QMessageBox::critical(this, "Ошибка!", "Измените значение переменной d");
        //QMessageBox::critical(this, "( ͡° ͜ʖ ͡ -)", "А ты шалун!\nБудь лапочкой, поменяй значение переменной d");
        return false;
    }
    ui->lineEditE->text().toDouble(&boobl);
    if (boobl)
    {
        E = ui->lineEditE->text().toDouble();
    }
    else
    {
        QMessageBox::critical(this, "Ошибка!", "Измените значение переменной e");
        //QMessageBox::critical(this, "( ͡° ͜ʖ ͡ -)", "А ты шалун!\nБудь лапочкой, поменяй значение переменной e");
        return false;
    }

    MyStackDouble stack;
    std::string str = line.toStdString();
    for (char& c : str) {
        double result = 0;
        if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e') {
            switch(c){
            case 'a':
                stack.push(A);
                break;
            case 'b':
                stack.push(B);
                break;
            case 'c':
                stack.push(C);
                break;
            case 'd':
                stack.push(D);
                break;
            case 'e':
                stack.push(E);
                break;
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            double op2 = stack.topElement()->element;
            stack.pop();
            double op1 = stack.topElement()->element;
            stack.pop();
            double result;
            switch (c) {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                if(op2 == 0) throw "Division by zero";
                result = op1 / op2;
                break;
            }
            stack.push(result);
        }
    }
    value = stack.topElement()->element;
    return true;
}



void MainWindow::on_evaluate1_clicked()
{
    answer = OPZ(ui->comboBox->currentText());
    try {
        double value;
       if( evaluation(answer, value))
        ui->textBrowser->setText("Ответ: " + QString::number(value) + "\nОПЗ: " + answer);
       else
           return;
    } catch (const char* msg) {
        QMessageBox::critical(this, "Ошибка.", "Деление на ноль.");
    }
}








