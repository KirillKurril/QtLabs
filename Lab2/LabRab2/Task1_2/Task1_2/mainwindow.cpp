#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->fullListButton->setEnabled(0);
    ui->dataByFieldButton->setEnabled(0);
    ui->addBookButton->setEnabled(0);
    ui->deleteBookButton->setEnabled(0);
    ui->sortButton->setEnabled(0);


    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFileButton_clicked(bool firstTime = 0)
{
    QString backup = fileAdress;
    if(!firstTime) fileAdress = QFileDialog::getOpenFileName(this, "Открыть файл", "C:/Users/dzmitry/source/repos/2semestr/LabRab2/Task1_2/Task1_2", "Text files (*.txt)");
    QFile file(fileAdress);
    file.open(QIODevice::ReadWrite);
    if((file.size() == 0) && !firstTime){
        QMessageBox::critical(this, "Ошибка", "Файл пуст.");
        fileAdress = backup;
        return;
    }
    booksNumber = 0;
    while(!file.atEnd()){
        QString line = file.readLine();
        ++booksNumber;
        QStringList lineList = line.split(" ");
        if((lineList.count() != 6)
                || (lineList[0].toInt() <= 0)
                || (lineList[5].toInt() <= 0)
                || (QDate::fromString(lineList[3], "dd.MM.yyyy").isValid() == 0)){
            QMessageBox::critical(this, "Ошибка", "Некорректный файл.");
            fileAdress = backup;
            return;
        }

    }
    LIST.deleteList();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    file.seek(0);
    while(!file.atEnd()){
        QString line = file.readLine();
        QStringList lineList = line.split(" ");

        LIST.pushBack(lineList[0].toInt(), lineList[5].toInt(), lineList[1], lineList[2], lineList[4], QDate::fromString(lineList[3], "dd.MM.yyyy"));
    }
    if(!firstTime){
        QMessageBox::information(this, "Информация", "Файл успешно открыт.");
        ui->addBookButton->setEnabled(0);
        ui->deleteBookButton->setEnabled(0);
    }
    else on_fullListButton_clicked();
    ui->fullListButton->setEnabled(1);
    ui->dataByFieldButton->setEnabled(1);
    ui->sortButton->setEnabled(1);
    ui->tableWidget->resizeColumnsToContents();
    file.close();
}

void MainWindow::on_fullListButton_clicked()
{
    ui->addBookButton->setEnabled(1);
    ui->deleteBookButton->setEnabled(1);
    ui->sortButton->setEnabled(1);
    ui->tableWidget->setRowCount(LIST.getAmount());
    for(int i = 0; i < LIST.getAmount(); ++i){
        NodeArray temp = LIST.getNode(i + 1);

        QTableWidgetItem *item = new QTableWidgetItem(QString::number(temp.bookID));
        ui->tableWidget->setItem(i, 0, item);

        std::string str = temp.author.toStdString();
        while(str.find('*', 0) != std::string::npos){
            int pos = str.find('*', 0);
            str.erase(pos, 1);
            str.insert(pos, 1, ' ');
        }
        item = new QTableWidgetItem(QString::fromStdString(str));
        ui->tableWidget->setItem(i, 1, item);

        str = temp.name.toStdString();
        while(str.find('*', 0) != std::string::npos){
            int pos = str.find('*', 0);
            str.erase(pos, 1);
            str.insert(pos, 1, ' ');
        }
        item = new QTableWidgetItem(QString::fromStdString(str));
        ui->tableWidget->setItem(i, 2, item);

        item = new QTableWidgetItem(temp.date.toString("dd.MM.yyyy"));
        ui->tableWidget->setItem(i, 3, item);

        str = temp.publisher.toStdString();
        while(str.find('*', 0) != std::string::npos){
            int pos = str.find('*', 0);
            str.erase(pos, 1);
            str.insert(pos, 1, ' ');
        }
        item = new QTableWidgetItem(QString::fromStdString(str));
        ui->tableWidget->setItem(i, 4, item);

        item = new QTableWidgetItem(QString::number(temp.pageNumber));
        ui->tableWidget->setItem(i, 5, item);
    }
    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::on_dataByFieldButton_clicked()
{
    int index = ui->comboBox->currentIndex();
    NodeArray temp;
    QString line;
    QDate date;
    int id, page;
    bool ok;
    switch(index){
        case 0:
            id = QInputDialog::getInt(this, "Введите регистрационный номер", "Введите регистрационный номер:", 1, 1, 2147483647, 1, &ok);
            if(ok){
                int amount = 0;
                for(int i = 1; i <= LIST.getAmount(); ++i){
                    temp = LIST.getNode(i);
                    if (temp.bookID == id) ++amount;
                }
                if(!amount){
                    QMessageBox::critical(this, "Ошибка", "Не найдено соответствующих параметров.");
                    ui->tableWidget->setRowCount(0);
                }
                else{
                    ui->tableWidget->clearContents();
                    ui->tableWidget->setRowCount(amount);
                    amount = 0;
                    for(int i = 1; i <= LIST.getAmount(); ++i){
                        temp = LIST.getNode(i);
                        if (temp.bookID == id){
                            QTableWidgetItem *item = new QTableWidgetItem(QString::number(temp.bookID));
                            ui->tableWidget->setItem(amount, 0, item);

                            std::string str = temp.author.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 1, item);

                            str = temp.name.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 2, item);

                            item = new QTableWidgetItem(temp.date.toString("dd.MM.yyyy"));
                            ui->tableWidget->setItem(amount, 3, item);

                            str = temp.publisher.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 4, item);

                            item = new QTableWidgetItem(QString::number(temp.pageNumber));
                            ui->tableWidget->setItem(amount, 5, item);
                            ++amount;
                        }
                    }
                }
            }
            break;


        case 1:
            line = QInputDialog::getText(this, "Введите автора", "Введите автора:",  QLineEdit::Normal, "", &ok);
            if(ok && !line.isEmpty()){
                int amount = 0;
                std::string str = line.toStdString();
                while(str.find(' ', 0) != std::string::npos){
                    int pos = str.find(' ', 0);
                    str.erase(pos, 1);
                    str.insert(pos, 1, '*');
                }
                line = QString::fromStdString(str);
                for(int i = 1; i <= LIST.getAmount(); ++i){
                    temp = LIST.getNode(i);
                    if (temp.author == line) ++amount;
                }
                if(!amount){
                    QMessageBox::critical(this, "Ошибка", "Не найдено соответствующих параметров.");
                    ui->tableWidget->setRowCount(0);
                }
                else{
                    ui->tableWidget->clearContents();
                    ui->tableWidget->setRowCount(amount);
                    amount = 0;
                    for(int i = 1; i <= LIST.getAmount(); ++i){
                        temp = LIST.getNode(i);
                        if (temp.author == line){
                            QTableWidgetItem *item = new QTableWidgetItem(QString::number(temp.bookID));
                            ui->tableWidget->setItem(amount, 0, item);

                            std::string str = temp.author.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 1, item);

                            str = temp.name.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 2, item);

                            item = new QTableWidgetItem(temp.date.toString("dd.MM.yyyy"));
                            ui->tableWidget->setItem(amount, 3, item);

                            str = temp.publisher.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 4, item);

                            item = new QTableWidgetItem(QString::number(temp.pageNumber));
                            ui->tableWidget->setItem(amount, 5, item);
                            ++amount;
                        }
                    }
                }
            }
            break;


        case 2:
            line = QInputDialog::getText(this, "Введите название", "Введите название:",  QLineEdit::Normal, "", &ok);
            if(ok && !line.isEmpty()){
                int amount = 0;
                std::string str = line.toStdString();
                while(str.find(' ', 0) != std::string::npos){
                    int pos = str.find(' ', 0);
                    str.erase(pos, 1);
                    str.insert(pos, 1, '*');
                }
                line = QString::fromStdString(str);
                for(int i = 1; i <= LIST.getAmount(); ++i){
                    temp = LIST.getNode(i);
                    if (temp.name == line) ++amount;
                }
                if(!amount){
                    QMessageBox::critical(this, "Ошибка", "Не найдено соответствующих параметров.");
                    ui->tableWidget->setRowCount(0);
                }
                else{
                    ui->tableWidget->clearContents();
                    ui->tableWidget->setRowCount(amount);
                    amount = 0;
                    for(int i = 1; i <= LIST.getAmount(); ++i){
                        temp = LIST.getNode(i);
                        if (temp.name == line){
                            QTableWidgetItem *item = new QTableWidgetItem(QString::number(temp.bookID));
                            ui->tableWidget->setItem(amount, 0, item);

                            std::string str = temp.author.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 1, item);

                            str = temp.name.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 2, item);

                            item = new QTableWidgetItem(temp.date.toString("dd.MM.yyyy"));
                            ui->tableWidget->setItem(amount, 3, item);

                            str = temp.publisher.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 4, item);

                            item = new QTableWidgetItem(QString::number(temp.pageNumber));
                            ui->tableWidget->setItem(amount, 5, item);
                            ++amount;
                        }
                    }
                }
            }

            break;


        case 3:
            line = QInputDialog::getText(this, "Введите дату издательства", "Введите дату издательства(дд.мм.гггг):",  QLineEdit::Normal, "", &ok);
            date = QDate::fromString(line, "dd.MM.yyyy");
            if(ok && !line.isEmpty() && date.isValid()){
                int amount = 0;
                for(int i = 1; i <= LIST.getAmount(); ++i){
                    temp = LIST.getNode(i);
                    if (temp.date == date) ++amount;
                }
                if(!amount){
                    QMessageBox::critical(this, "Ошибка", "Не найдено соответствующих параметров.");
                    ui->tableWidget->setRowCount(0);
                }
                else{
                    ui->tableWidget->clearContents();
                    ui->tableWidget->setRowCount(amount);
                    amount = 0;
                    for(int i = 1; i <= LIST.getAmount(); ++i){
                        temp = LIST.getNode(i);
                        if (temp.date == date){
                            QTableWidgetItem *item = new QTableWidgetItem(QString::number(temp.bookID));
                            ui->tableWidget->setItem(amount, 0, item);

                            std::string str = temp.author.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 1, item);

                            str = temp.name.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 2, item);

                            item = new QTableWidgetItem(temp.date.toString("dd.MM.yyyy"));
                            ui->tableWidget->setItem(amount, 3, item);

                            str = temp.publisher.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 4, item);

                            item = new QTableWidgetItem(QString::number(temp.pageNumber));
                            ui->tableWidget->setItem(amount, 5, item);
                            ++amount;
                        }
                    }
                }
            }
            else QMessageBox::critical(this, "Ошибка", "Некорректная дата.");
            break;


        case 4:
            line = QInputDialog::getText(this, "Введите издательство", "Введите издательство:",  QLineEdit::Normal, "", &ok);
            if(ok && !line.isEmpty()){
                int amount = 0;
                std::string str = line.toStdString();
                while(str.find(' ', 0) != std::string::npos){
                    int pos = str.find(' ', 0);
                    str.erase(pos, 1);
                    str.insert(pos, 1, '*');
                }
                line = QString::fromStdString(str);
                for(int i = 1; i <= LIST.getAmount(); ++i){
                    temp = LIST.getNode(i);
                    if (temp.publisher == line) ++amount;
                }
                if(!amount){
                    QMessageBox::critical(this, "Ошибка", "Не найдено соответствующих параметров.");
                    ui->tableWidget->setRowCount(0);
                }
                else{
                    ui->tableWidget->clearContents();
                    ui->tableWidget->setRowCount(amount);
                    amount = 0;
                    for(int i = 1; i <= LIST.getAmount(); ++i){
                        temp = LIST.getNode(i);
                        if (temp.publisher == line){
                            QTableWidgetItem *item = new QTableWidgetItem(QString::number(temp.bookID));
                            ui->tableWidget->setItem(amount, 0, item);

                            std::string str = temp.author.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 1, item);

                            str = temp.name.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 2, item);

                            item = new QTableWidgetItem(temp.date.toString("dd.MM.yyyy"));
                            ui->tableWidget->setItem(amount, 3, item);

                            str = temp.publisher.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 4, item);

                            item = new QTableWidgetItem(QString::number(temp.pageNumber));
                            ui->tableWidget->setItem(amount, 5, item);
                            ++amount;
                        }
                    }
                }
            }
            break;


        case 5:
            page = QInputDialog::getInt(this, "Введите кол-во страниц", "Введите кол-во страниц", 1, 1, 2147483647, 1, &ok);
            if(ok){
                int amount = 0;
                for(int i = 1; i <= LIST.getAmount(); ++i){
                    temp = LIST.getNode(i);
                    if (temp.pageNumber == page) ++amount;
                }
                if(!amount){
                    QMessageBox::critical(this, "Ошибка", "Не найдено соответствующих параметров.");
                    ui->tableWidget->setRowCount(0);
                }
                else{
                    ui->tableWidget->clearContents();
                    ui->tableWidget->setRowCount(amount);
                    amount = 0;
                    for(int i = 1; i <= LIST.getAmount(); ++i){
                        temp = LIST.getNode(i);
                        if (temp.pageNumber == page){
                            QTableWidgetItem *item = new QTableWidgetItem(QString::number(temp.bookID));
                            ui->tableWidget->setItem(amount, 0, item);

                            std::string str = temp.author.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 1, item);

                            str = temp.name.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 2, item);

                            item = new QTableWidgetItem(temp.date.toString("dd.MM.yyyy"));
                            ui->tableWidget->setItem(amount, 3, item);

                            str = temp.publisher.toStdString();
                            while(str.find('*', 0) != std::string::npos){
                                int pos = str.find('*', 0);
                                str.erase(pos, 1);
                                str.insert(pos, 1, ' ');
                            }
                            item = new QTableWidgetItem(QString::fromStdString(str));
                            ui->tableWidget->setItem(amount, 4, item);

                            item = new QTableWidgetItem(QString::number(temp.pageNumber));
                            ui->tableWidget->setItem(amount, 5, item);
                            ++amount;
                        }
                    }
                }
            }
            break;
    }
    ui->addBookButton->setEnabled(0);
    ui->deleteBookButton->setEnabled(0);
    ui->sortButton->setEnabled(0);
}

void MainWindow::saveFile()
{
    QFile file(fileAdress);
    file.open(QIODevice::WriteOnly);
    QTextStream filestream(&file);
    for(int i = 1; i <= LIST.getAmount(); ++i){
        NodeArray temp;
        temp = LIST.getNode(i);
        filestream << temp.bookID << " " << temp.author << " " << temp.name << " " << temp.date.toString("dd.MM.yyyy") << " " << temp.publisher << " " << temp.pageNumber << "\n";
    }
    file.close();
}

void MainWindow::on_addBookButton_clicked()
{
    int id, page;
    QString author, name, publisher, line;
    QDate date;
    bool ok;
    NodeArray temp;


    id = QInputDialog::getInt(this, "Введите регистрационный номер", "Введите регистрационный номер:", 1, 1, 2147483647, 1, &ok);
    if(ok){
        for(int i = 1; i <= LIST.getAmount(); ++i){
            temp = LIST.getNode(i);
            if(temp.bookID == id){
                QMessageBox::critical(this, "Ошибка", "Данный номер уже занят.");
                return;
            }
        }
    }
    else return;


    author = QInputDialog::getText(this, "Введите автора", "Введите автора:", QLineEdit::Normal, "", &ok);
    std::string str = author.toStdString();
    while(str.find(' ', 0) != std::string::npos){
        int pos = str.find(' ', 0);
        str.erase(pos, 1);
        str.insert(pos, 1, '*');
    }
    author = QString::fromStdString(str);
    if(!ok) return;
    if(author.isEmpty()){
        QMessageBox::critical(this, "Ошибка", "Строка пуста.");
        return;
    }

    name = QInputDialog::getText(this, "Введите название", "Введите название:", QLineEdit::Normal, "", &ok);
    str = name.toStdString();
    while(str.find(' ', 0) != std::string::npos){
        int pos = str.find(' ', 0);
        str.erase(pos, 1);
        str.insert(pos, 1, '*');
    }
    name = QString::fromStdString(str);
    if(!ok) return;
    if(name.isEmpty()){
        QMessageBox::critical(this, "Ошибка", "Строка пуста.");
        return;
    }

    line = QInputDialog::getText(this, "Введите дату", "Введите дату(дд.мм.гггг):", QLineEdit::Normal, "", &ok);
    date = QDate::fromString(line, "dd.MM.yyyy");
    if(!ok) return;
    if(!date.isValid()){
        QMessageBox::critical(this, "Ошибка", "Некорректная дата");
        return;
    }

    publisher = QInputDialog::getText(this, "Введите издателя", "Введите издателя:", QLineEdit::Normal, "", &ok);
    str = publisher.toStdString();
    while(str.find(' ', 0) != std::string::npos){
        int pos = str.find(' ', 0);
        str.erase(pos, 1);
        str.insert(pos, 1, '*');
    }
    publisher = QString::fromStdString(str);
    if(!ok) return;
    if(publisher.isEmpty()){
        QMessageBox::critical(this, "Ошибка", "Строка пуста.");
        return;
    }

    page = QInputDialog::getInt(this, "Введите кол-во страниц", "Введите кол-во страниц:", 1, 1, 2147483647, 1, &ok);
    if(!ok) return;
    LIST.pushBack(id, page, author, name, publisher, date);
    saveFile();
    on_openFileButton_clicked(1);
}

void MainWindow::on_deleteBookButton_clicked()
{
    bool ok, deleted = 0;;
    int id = QInputDialog::getInt(this, "Введите регистрационный номер", "Введите регистрационный номер:", 1, 1, 2147483647, 1, &ok);
    if(ok){
        for(int i = 1; i <= LIST.getAmount(); ++i){
            NodeArray temp;
            temp = LIST.getNode(i);
            if(temp.bookID == id){
                deleted = 1;
                LIST.deleteNode(i);
                saveFile();
                on_openFileButton_clicked(1);
                return;
            }
        }
        if(!deleted) QMessageBox::critical(this, "Ошибка", "Не найдено соответствующих параметров.");
    }
}

void MainWindow::on_sortButton_clicked()
{
    LIST.insertionSort();
    saveFile();
    on_fullListButton_clicked();
}
