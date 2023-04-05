#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QRegularExpressionValidator validator(QRegularExpression("^-?\\d+(\\.\\d+)?$"));
    ui->setupUi(this);
    connect(ui->mp1, &QCheckBox::clicked, ui->mm1, &QCheckBox::setChecked);
    connect(ui->mp2, &QCheckBox::clicked, ui->mm2, &QCheckBox::setChecked);
    connect(ui->mp3, &QCheckBox::clicked, ui->mm3, &QCheckBox::setChecked);

    connect(ui->pp1, &QCheckBox::clicked, ui->pm1, &QCheckBox::setChecked);
    connect(ui->pp2, &QCheckBox::clicked, ui->pm2, &QCheckBox::setChecked);
    connect(ui->pp2, &QCheckBox::clicked, ui->pm3, &QCheckBox::setChecked);

    connect(ui->hdp1, &QCheckBox::clicked, ui->hdm1, &QCheckBox::setChecked);
    connect(ui->hdp2, &QCheckBox::clicked, ui->hdm2, &QCheckBox::setChecked);
    connect(ui->hdp2, &QCheckBox::clicked, ui->hdm3, &QCheckBox::setChecked);

    connect(ui->rap1, &QCheckBox::clicked, ui->ram1, &QCheckBox::setChecked);
    connect(ui->rap1, &QCheckBox::clicked, ui->ram2, &QCheckBox::setChecked);
    connect(ui->rap2, &QCheckBox::clicked, ui->ram3, &QCheckBox::setChecked);

    connect(ui->psp1, &QCheckBox::clicked, ui->psm1, &QCheckBox::setChecked);
    connect(ui->psp2, &QCheckBox::clicked, ui->psm2, &QCheckBox::setChecked);
    connect(ui->psp3, &QCheckBox::clicked, ui->psm3, &QCheckBox::setChecked);

    connect(ui->cp1, &QCheckBox::clicked, ui->cm1, &QCheckBox::setChecked);
    connect(ui->cp2, &QCheckBox::clicked, ui->cm2, &QCheckBox::setChecked);
    connect(ui->cp3, &QCheckBox::clicked, ui->cm3, &QCheckBox::setChecked);

    for(int i = 1; i < 19; i++)
    {
        Good good(i);
        if (good.getType() == "motherboard")
        {
        motherboards.push_back(good);
        continue;
        }
        if (good.getType() == "processor")
        {
            processors.push_back(good);
        continue;
        }
        if (good.getType() == "RAM")
        {
            rams.push_back(good);
        continue;
        }
        if (good.getType() == "ROM")
        {
            roms.push_back(good);
        continue;
        }

        if (good.getType() == "power unit")
        {
            power_units.push_back(good);
        continue;
        }
        if (good.getType() == "case")
        {
        cases.push_back(good);
        continue;
        }
        //Goods.push_back(good);

    }
    QMainWindow::setStyleSheet("QMainWindow { background-color: #83aca6; }");
    //ui->menubar->setStyleSheet("background-color: ##304744;");
    //ui->statusbar->setStyleSheet("background-color: ##304744;");
    ui->label_24->setStyleSheet("background-color: #ac8389; border-radius: 10px;");

    //ui->label_2->setStyleSheet("background-color: #b8cfcc; border-radius: 10px;");
    //ui->label_55->setStyleSheet("background-color: #704b50; border-radius: 10px;");
    ui->label->setStyleSheet("color: white;");
    ui->label_54->setStyleSheet("background-image: url(\"C:/C++/Labs/Lab1/LWD2/resources/img1.jpg\"); background-repeat: no-repeat; background-position: center;");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bool ok;
    QString zxc = ui->lineEdit->text();
    zxc.toDouble(&ok);
    if(ok)
    {
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(0);
    qint64 i = 0;
    for(int a = 0; a < motherboards.size(); a++)//(auto mother_i : motherboards)
    {
        if((a == 0 && ui->mm1->isChecked()) | (a == 1 && ui->mm2->isChecked()) | (a == 2 && ui->mm3->isChecked()))
        for(int j = 0; j < processors.size(); j++)//(auto proc_i : processors)
        {
            if((j == 0 && ui->pm1->isChecked()) | (j == 1 && ui->pm2->isChecked()) | (j == 2 && ui->pm3->isChecked()))
            for(int k = 0; k < rams.size(); k++)//(auto ram_i : rams)
            {
                if((k == 0 && ui->ram1->isChecked()) | (k == 1 && ui->ram2->isChecked()) | (k == 2 && ui->ram3->isChecked()))
                for(int z = 0; z < roms.size(); z++)//(auto rom_i: roms)
                {
                    if((z == 0 && ui->hdm1->isChecked()) | (z == 1 && ui->hdm2->isChecked()) | (z == 2 && ui->hdm3->isChecked()))
                    for(int p = 0; p < power_units.size(); p++)//(auto power_unit_i: power_units)
                    {
                        if((p == 0 && ui->psm1->isChecked()) | (p == 1 && ui->psm2->isChecked()) | (p == 2 && ui->psm3->isChecked()))
                        for(int r = 0; r < cases.size(); r++)//(auto case_i: cases)
                        {
                             if((r == 0 && ui->cm1->isChecked()) | (r == 1 && ui->cm2->isChecked()) | (r == 2 && ui->cm3->isChecked()))
                            {
                            qint64 cost;
                            if(motherboards[a].getPrice().toFloat() + processors[j].getPrice().toFloat() + rams[k].getPrice().toFloat() + roms[z].getPrice().toFloat() + power_units[p].getPrice().toFloat() + cases[r].getPrice().toFloat() <= ui->lineEdit->text().toDouble())
                            {
                            ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 32);
                            ui->tableWidget->setItem(i*32, 0, new QTableWidgetItem("Сборка №"));
                            ui->tableWidget->setItem(i*32, 1, new QTableWidgetItem(QString::number(i + 1)));

                                    ui->tableWidget->setItem(i*32 + 1, 0, new QTableWidgetItem("Материнская плата:" ));

                                    ui->tableWidget->setItem(i*32 + 2, 0, new QTableWidgetItem("Производитель:" ));
                                    ui->tableWidget->setItem(i*32 + 3, 0, new QTableWidgetItem("Модель:" ));
                                    ui->tableWidget->setItem(i*32 + 4, 0, new QTableWidgetItem("Параметры:"));
                                    ui->tableWidget->setItem(i*32 + 5, 0, new QTableWidgetItem("Цена:" ));

                                    ui->tableWidget->setItem(i*32 + 2, 1, new QTableWidgetItem(motherboards[a].getManufacturer()));
                                    ui->tableWidget->setItem(i*32 + 3, 1, new QTableWidgetItem(motherboards[a].getModel() ));
                                    ui->tableWidget->setItem(i*32 + 4, 1, new QTableWidgetItem(motherboards[a].getParameters( )));
                                    ui->tableWidget->setItem(i*32 + 5, 1, new QTableWidgetItem(motherboards[a].getPrice()));



                                    ui->tableWidget->setItem(i*32 + 6, 0, new QTableWidgetItem("Процессор:"));

                                    ui->tableWidget->setItem(i*32 + 7, 0, new QTableWidgetItem("Производитель:"));
                                    ui->tableWidget->setItem(i*32 + 8, 0, new QTableWidgetItem("Модель:"));
                                    ui->tableWidget->setItem(i*32 + 9, 0, new QTableWidgetItem("Параметры:"));
                                    ui->tableWidget->setItem(i*32 + 10, 0, new QTableWidgetItem("Цена:"));

                                    ui->tableWidget->setItem(i*32 + 7, 1, new QTableWidgetItem(processors[j].getManufacturer()));
                                    ui->tableWidget->setItem(i*32 + 8, 1, new QTableWidgetItem(processors[j].getModel()));
                                    ui->tableWidget->setItem(i*32 + 9, 1, new QTableWidgetItem(processors[j].getParameters()));
                                    ui->tableWidget->setItem(i*32 + 10, 1, new QTableWidgetItem(processors[j].getPrice()));

                                    ui->tableWidget->setItem(i*32 + 11, 0, new QTableWidgetItem("Оперативная память:"));

                                    ui->tableWidget->setItem(i*32 + 12, 0, new QTableWidgetItem("Производитель:"));
                                    ui->tableWidget->setItem(i*32 + 13, 0, new QTableWidgetItem("Модель:"));
                                    ui->tableWidget->setItem(i*32 + 14, 0, new QTableWidgetItem("Параметры:"));
                                    ui->tableWidget->setItem(i*32 + 15, 0, new QTableWidgetItem("Цена:"));

                                    ui->tableWidget->setItem(i*32 + 12, 1, new QTableWidgetItem(rams[k].getManufacturer()));
                                    ui->tableWidget->setItem(i*32 + 13, 1, new QTableWidgetItem(rams[k].getModel()));
                                    ui->tableWidget->setItem(i*32 + 14, 1, new QTableWidgetItem(rams[k].getParameters()));
                                    ui->tableWidget->setItem(i*32 + 15, 1, new QTableWidgetItem(rams[k].getPrice()));

                                    ui->tableWidget->setItem(i*32 + 16, 0, new QTableWidgetItem("Накопитель:"));

                                    ui->tableWidget->setItem(i*32 + 17, 0, new QTableWidgetItem("Производитель:"));
                                    ui->tableWidget->setItem(i*32 + 18, 0, new QTableWidgetItem("Модель:"));
                                    ui->tableWidget->setItem(i*32 + 19, 0, new QTableWidgetItem("Параметры:"));
                                    ui->tableWidget->setItem(i*32 + 20, 0, new QTableWidgetItem("Цена:"));

                                    ui->tableWidget->setItem(i*32 + 17, 1, new QTableWidgetItem(roms[z].getManufacturer()));
                                    ui->tableWidget->setItem(i*32 + 18, 1, new QTableWidgetItem(roms[z].getModel()));
                                    ui->tableWidget->setItem(i*32 + 19, 1, new QTableWidgetItem(roms[z].getParameters()));
                                    ui->tableWidget->setItem(i*32 + 20, 1, new QTableWidgetItem(roms[z].getPrice()));

                                    ui->tableWidget->setItem(i*32 + 21, 0, new QTableWidgetItem("Блок питания:"));

                                    ui->tableWidget->setItem(i*32 + 22, 0, new QTableWidgetItem("Производитель:"));
                                    ui->tableWidget->setItem(i*32 + 23, 0, new QTableWidgetItem("Модель:"));
                                    ui->tableWidget->setItem(i*32 + 24, 0, new QTableWidgetItem("Параметры:"));
                                    ui->tableWidget->setItem(i*32 + 25, 0, new QTableWidgetItem("Цена:"));

                                    ui->tableWidget->setItem(i*32 + 22, 1, new QTableWidgetItem(power_units[p].getManufacturer()));
                                    ui->tableWidget->setItem(i*32 + 23, 1, new QTableWidgetItem(power_units[p].getModel()));
                                    ui->tableWidget->setItem(i*32 + 24, 1, new QTableWidgetItem(power_units[p].getParameters()));
                                    ui->tableWidget->setItem(i*32 + 25, 1, new QTableWidgetItem(power_units[p].getPrice()));

                                    ui->tableWidget->setItem(i*32 + 26, 0, new QTableWidgetItem("Корпус:"));

                                    ui->tableWidget->setItem(i*32 + 27, 0, new QTableWidgetItem("Производитель:"));
                                    ui->tableWidget->setItem(i*32 + 28, 0, new QTableWidgetItem("Модель:"));
                                    ui->tableWidget->setItem(i*32 + 29, 0, new QTableWidgetItem("Параметры:"));
                                    ui->tableWidget->setItem(i*32 + 30, 0, new QTableWidgetItem("Цена:"));

                                    ui->tableWidget->setItem(i*32 + 27, 1, new QTableWidgetItem(cases[r].getManufacturer()));
                                    ui->tableWidget->setItem(i*32 + 28, 1, new QTableWidgetItem(cases[r].getModel()));
                                    ui->tableWidget->setItem(i*32 + 29, 1, new QTableWidgetItem(cases[r].getParameters()));
                                    ui->tableWidget->setItem(i*32 + 30, 1, new QTableWidgetItem(cases[r].getPrice()));
                                    i++;
                            }
                            }
                        }
                    }
                }
            }
        }
    }
      ui->tableWidget->resizeColumnsToContents();
    }
    else
    {
        QMessageBox::warning(this,"Warning", "Вы ввели некорректный ценовой диапазон!");
    }
}


