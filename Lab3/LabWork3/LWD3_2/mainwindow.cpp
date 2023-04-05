#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include"cock.h"

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

    QString v11 =ui->tableWidget->item(1, 0)->text();
    if(!v11.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString v12 =ui->tableWidget->item(2, 0)->text();
    if(!v12.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString v13 =ui->tableWidget->item(3, 0)->text();
    if(!v13.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}

    QString v21 =ui->tableWidget->item(1, 2)->text();
    if(!v21.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString v22 =ui->tableWidget->item(2, 2)->text();
    if(!v22.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString v23 =ui->tableWidget->item(3, 2)->text();
    if(!v23.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}

    QString v31 =ui->tableWidget->item(5, 0)->text();
    if(!v31.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString v32 =ui->tableWidget->item(6, 0)->text();
    if(!v32.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString v33 =ui->tableWidget->item(7, 0)->text();
    if(!v33.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}

    QString v41 =ui->tableWidget->item(5, 2)->text();
    if(!v41.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString v42 =ui->tableWidget->item(6, 2)->text();
    if(!v42.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString v43 =ui->tableWidget->item(7, 2)->text();
    if(!v43.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}

    QString p11 =ui->tableWidget->item(1, 4)->text();
    if(!p11.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString p12 =ui->tableWidget->item(2, 4)->text();
    if(!p12.toDouble()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}

    QString p21 =ui->tableWidget->item(1, 5)->text();
    if(!p21.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString p22 =ui->tableWidget->item(2, 5)->text();
    if(!p22.toDouble()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}

    QString p31 =ui->tableWidget->item(1, 6)->text();
    if(!p31.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString p32 =ui->tableWidget->item(2, 6)->text();
    if(!p32.toDouble()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}

    QString p41 =ui->tableWidget->item(5, 4)->text();
    if(!p41.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString p42 =ui->tableWidget->item(6, 4)->text();
    if(!p42.toDouble()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}

    QString p51 =ui->tableWidget->item(5, 5)->text();
    if(!p51.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString p52 =ui->tableWidget->item(6, 5)->text();
    if(!p52.toDouble()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}

    QString p61 =ui->tableWidget->item(5, 6)->text();
    if(!p61.toInt()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}
    QString p62 =ui->tableWidget->item(6, 6)->text();
    if(!p62.toDouble()){QMessageBox::warning(this, "Ошибка!", "Проверьте правильность данных, введённых в таблицу!"); return;}

    //vdv.push_back(DPair<DPair<DVector<QString>,DVector<QString>>,DVector<DPair<QString,QString>>>);

    DVector<QString> v1(v11, v12, v13);
    DVector<QString> v2(v21, v22, v23);
    DPair<DVector<QString>, DVector<QString>> pv1 (v1, v2);

    DVector<QString> v3(v31, v32, v33);
    DVector<QString> v4(v41, v42, v43);
    DPair<DVector<QString>, DVector<QString>> pv2 (v3, v4);

    DPair<QString, QString> p1(p11, p12);
    DPair<QString, QString> p2(p21, p22);
    DPair<QString, QString> p3(p31, p32);
    DVector<DPair<QString, QString>> vp1(p1, p2, p3);

    DPair<QString, QString> p4(p41, p42);
    DPair<QString, QString> p5(p51, p52);
    DPair<QString, QString> p6(p61, p62);
    DVector<DPair<QString, QString>> vp2(p4, p5, p6);

    DPair<DPair<DVector<QString>, DVector<QString>>, DVector<DPair<QString, QString>>> ppvvp1(pv1, vp1);
    DPair<DPair<DVector<QString>, DVector<QString>>, DVector<DPair<QString, QString>>> ppvvp2(pv2, vp2);

    DVector<DPair<DPair<DVector<QString>, DVector<QString>>, DVector<DPair<QString, QString>>>> papavepagemabody(ppvvp1, ppvvp2);
    qDebug() << sizeof(papavepagemabody);

    QString matrix1 = "";
    for(int i = 0; i < 3; i++)
    {
        matrix1 += papavepagemabody[0].first.first[i] + " ";

    }
    matrix1 +="\n\n";
    for(int i = 0; i < 3; i++)
    {
        matrix1 += papavepagemabody[1].first.first[i] + " ";

    }
    ui->mat1->setText(matrix1);

    QString matrix2 = "";
    for(int i = 0; i < 3; i++)
    {
        matrix2 += papavepagemabody[0].second[i].first + ", " + papavepagemabody[0].second[i].second + " ";
        matrix2 += '\n';
    }
    matrix2 += '\n';
    for(int i = 0; i < 3; i++)
    {
        matrix2 += papavepagemabody[1].second[i].first + ", " + papavepagemabody[1].second[i].second + " ";
        matrix2 += '\n';
    }
    ui->mat2->setText(matrix2);

}


void MainWindow::on_pushButton_2_clicked()
{
    QString p11 =ui->tableWidget_2->item(1, 0)->text();
    QString p12 =ui->tableWidget_2->item(2, 0)->text();
    QString p21 =ui->tableWidget_2->item(1, 2)->text();
    QString p22 =ui->tableWidget_2->item(2, 2)->text();
    QString p31 =ui->tableWidget_2->item(4, 0)->text();
    QString p32 =ui->tableWidget_2->item(5, 0)->text();
    QString p41 =ui->tableWidget_2->item(4, 2)->text();
    QString p42 =ui->tableWidget_2->item(5, 2)->text();
    QString p51 =ui->tableWidget_2->item(1, 4)->text();
    QString p52 =ui->tableWidget_2->item(2, 4)->text();
    QString p61 =ui->tableWidget_2->item(1, 6)->text();
    QString p62 =ui->tableWidget_2->item(2, 6)->text();
    QString p71 =ui->tableWidget_2->item(4, 4)->text();
    QString p72 =ui->tableWidget_2->item(5, 4)->text();
    QString p81 =ui->tableWidget_2->item(4, 6)->text();
    QString p82 =ui->tableWidget_2->item(5, 6)->text();

    DPair<QString, QString> p1(p11, p12);
    DPair<QString, QString> p2(p21, p22);
    DPair<QString, QString> p3(p31, p32);
    DPair<QString, QString> p4(p41, p42);
    DPair<QString, QString> p5(p51, p52);
    DPair<QString, QString> p6(p61, p62);
    DPair<QString, QString> p7(p71, p72);
    DPair<QString, QString> p8(p81, p82);
    DPair<DPair<QString, QString>,DPair<QString, QString>> pp1(p1, p2);
    DPair<DPair<QString, QString>,DPair<QString, QString>> pp2(p3, p4);
    DPair<DPair<QString, QString>,DPair<QString, QString>> pp3(p5, p6);
    DPair<DPair<QString, QString>,DPair<QString, QString>> pp4(p7, p8);
    DPair<DPair<DPair<QString, QString>,DPair<QString, QString>>,DPair<DPair<QString, QString>,DPair<QString, QString>>> ppp1(pp1, pp3);
    DPair<DPair<DPair<QString, QString>,DPair<QString, QString>>,DPair<DPair<QString, QString>,DPair<QString, QString>>> ppp2(pp2, pp4);
    DPair< DPair<DPair<DPair<QString, QString>,DPair<QString, QString>>,DPair<DPair<QString, QString>,DPair<QString, QString>>>, DPair<DPair<DPair<QString, QString>,DPair<QString, QString>>,DPair<DPair<QString, QString>,DPair<QString, QString>>>> pppp1(ppp1, ppp2);

    ui->mat1->setText(pppp1.first.first.first.first + " " + pppp1.first.first.first.second + "\n" + pppp1.second.first.first.first + " " + pppp1.second.first.first.second);

    ui->mat2->setText(pppp1.first.second.first.first + " " + pppp1.first.second.first.second + "\n" + pppp1.first.second.second.first + " " + pppp1.first.second.second.second + "\n\n" + pppp1.second.second.first.first + " " + pppp1.second.second.first.second + "\n" + pppp1.second.second.second.first + " " + pppp1.second.second.second.second + "\n\n");
}

