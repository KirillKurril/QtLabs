/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_55;
    QLabel *label_18;
    QLabel *label_24;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *gridLayout;
    QCheckBox *cp3;
    QLabel *label_10;
    QCheckBox *cm3;
    QCheckBox *psm2;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_23;
    QLabel *label_9;
    QCheckBox *psm1;
    QCheckBox *cp2;
    QCheckBox *cm1;
    QCheckBox *psm3;
    QCheckBox *psp1;
    QCheckBox *cp1;
    QCheckBox *psp3;
    QCheckBox *psp2;
    QCheckBox *cm2;
    QLabel *label_22;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_51;
    QLabel *label_52;
    QCheckBox *hdp1;
    QCheckBox *hdp2;
    QLabel *label_57;
    QLabel *label_49;
    QCheckBox *hdm1;
    QCheckBox *hdm2;
    QCheckBox *hdm3;
    QLabel *label_50;
    QLabel *label_48;
    QCheckBox *rap1;
    QCheckBox *rap2;
    QLabel *label_58;
    QLabel *label_53;
    QCheckBox *ram1;
    QCheckBox *ram2;
    QCheckBox *ram3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_42;
    QLabel *label_43;
    QCheckBox *mp1;
    QCheckBox *mp2;
    QCheckBox *mp3;
    QLabel *label_45;
    QCheckBox *mm1;
    QCheckBox *mm2;
    QCheckBox *mm3;
    QLabel *label_44;
    QLabel *label_47;
    QCheckBox *pp1;
    QCheckBox *pp2;
    QLabel *label_56;
    QLabel *label_46;
    QCheckBox *pm1;
    QCheckBox *pm2;
    QCheckBox *pm3;
    QLabel *label_3;
    QLabel *label_54;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1343, 748);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_55 = new QLabel(centralwidget);
        label_55->setObjectName("label_55");
        label_55->setGeometry(QRect(620, 20, 711, 81));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(40, 100, 251, 1351));
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(620, 130, 711, 501));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(630, 20, 691, 85));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setEnabled(true);
        lineEdit->setMinimumSize(QSize(189, 22));
        lineEdit->setMaximumSize(QSize(189, 22));

        verticalLayout->addWidget(lineEdit, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(pushButton, 0, Qt::AlignHCenter);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(630, 130, 691, 491));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");

        gridLayout_3->addLayout(verticalLayout_3, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 28));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_4, 0, Qt::AlignVCenter);


        gridLayout_3->addLayout(verticalLayout_5, 1, 1, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");

        gridLayout_3->addLayout(verticalLayout_7, 1, 2, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        cp3 = new QCheckBox(gridLayoutWidget);
        cp3->setObjectName("cp3");
        cp3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(cp3, 18, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName("label_10");
        label_10->setMinimumSize(QSize(0, 27));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font1.setPointSize(10);
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_10->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_10, 14, 0, 1, 1);

        cm3 = new QCheckBox(gridLayoutWidget);
        cm3->setObjectName("cm3");
        cm3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(cm3, 23, 0, 1, 1);

        psm2 = new QCheckBox(gridLayoutWidget);
        psm2->setObjectName("psm2");
        psm2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(psm2, 12, 0, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName("label_17");
        label_17->setMinimumSize(QSize(0, 20));
        label_17->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_17->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label_17, 15, 0, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName("label_16");
        label_16->setMinimumSize(QSize(0, 20));
        label_16->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_16->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label_16, 5, 0, 1, 1);

        label_23 = new QLabel(gridLayoutWidget);
        label_23->setObjectName("label_23");
        label_23->setMinimumSize(QSize(0, 20));
        label_23->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_23->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label_23, 19, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(0, 27));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_9->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        psm1 = new QCheckBox(gridLayoutWidget);
        psm1->setObjectName("psm1");
        psm1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(psm1, 11, 0, 1, 1);

        cp2 = new QCheckBox(gridLayoutWidget);
        cp2->setObjectName("cp2");
        cp2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(cp2, 17, 0, 1, 1);

        cm1 = new QCheckBox(gridLayoutWidget);
        cm1->setObjectName("cm1");
        cm1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(cm1, 20, 0, 1, 1);

        psm3 = new QCheckBox(gridLayoutWidget);
        psm3->setObjectName("psm3");
        psm3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(psm3, 13, 0, 1, 1);

        psp1 = new QCheckBox(gridLayoutWidget);
        psp1->setObjectName("psp1");
        psp1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(psp1, 6, 0, 1, 1);

        cp1 = new QCheckBox(gridLayoutWidget);
        cp1->setObjectName("cp1");
        cp1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(cp1, 16, 0, 1, 1);

        psp3 = new QCheckBox(gridLayoutWidget);
        psp3->setObjectName("psp3");
        psp3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(psp3, 8, 0, 1, 1);

        psp2 = new QCheckBox(gridLayoutWidget);
        psp2->setObjectName("psp2");
        psp2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(psp2, 7, 0, 1, 1);

        cm2 = new QCheckBox(gridLayoutWidget);
        cm2->setObjectName("cm2");
        cm2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        gridLayout->addWidget(cm2, 22, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget);
        label_22->setObjectName("label_22");
        label_22->setMinimumSize(QSize(0, 20));
        QPalette palette;
        QBrush brush(QColor(51, 34, 37, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        label_22->setPalette(palette);
        label_22->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_22->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label_22, 10, 0, 1, 1);


        verticalLayout_8->addLayout(gridLayout);


        gridLayout_3->addLayout(verticalLayout_8, 2, 2, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_51 = new QLabel(gridLayoutWidget);
        label_51->setObjectName("label_51");
        label_51->setMinimumSize(QSize(0, 27));
        label_51->setFont(font1);
        label_51->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_51->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_6->addWidget(label_51);

        label_52 = new QLabel(gridLayoutWidget);
        label_52->setObjectName("label_52");
        label_52->setMinimumSize(QSize(0, 20));
        label_52->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_52->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_6->addWidget(label_52);

        hdp1 = new QCheckBox(gridLayoutWidget);
        hdp1->setObjectName("hdp1");
        hdp1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_6->addWidget(hdp1);

        hdp2 = new QCheckBox(gridLayoutWidget);
        hdp2->setObjectName("hdp2");
        hdp2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_6->addWidget(hdp2);

        label_57 = new QLabel(gridLayoutWidget);
        label_57->setObjectName("label_57");

        verticalLayout_6->addWidget(label_57);

        label_49 = new QLabel(gridLayoutWidget);
        label_49->setObjectName("label_49");
        label_49->setMinimumSize(QSize(0, 20));
        label_49->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_49->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_6->addWidget(label_49);

        hdm1 = new QCheckBox(gridLayoutWidget);
        hdm1->setObjectName("hdm1");
        hdm1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_6->addWidget(hdm1);

        hdm2 = new QCheckBox(gridLayoutWidget);
        hdm2->setObjectName("hdm2");
        hdm2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_6->addWidget(hdm2);

        hdm3 = new QCheckBox(gridLayoutWidget);
        hdm3->setObjectName("hdm3");
        hdm3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_6->addWidget(hdm3);

        label_50 = new QLabel(gridLayoutWidget);
        label_50->setObjectName("label_50");
        label_50->setMinimumSize(QSize(0, 27));
        label_50->setFont(font1);
        label_50->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_50->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_6->addWidget(label_50);

        label_48 = new QLabel(gridLayoutWidget);
        label_48->setObjectName("label_48");
        label_48->setMinimumSize(QSize(0, 20));
        label_48->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_48->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_6->addWidget(label_48);

        rap1 = new QCheckBox(gridLayoutWidget);
        rap1->setObjectName("rap1");
        rap1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_6->addWidget(rap1);

        rap2 = new QCheckBox(gridLayoutWidget);
        rap2->setObjectName("rap2");
        rap2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_6->addWidget(rap2);

        label_58 = new QLabel(gridLayoutWidget);
        label_58->setObjectName("label_58");

        verticalLayout_6->addWidget(label_58);

        label_53 = new QLabel(gridLayoutWidget);
        label_53->setObjectName("label_53");
        label_53->setMinimumSize(QSize(0, 20));
        label_53->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_53->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_6->addWidget(label_53);

        ram1 = new QCheckBox(gridLayoutWidget);
        ram1->setObjectName("ram1");
        ram1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_6->addWidget(ram1);

        ram2 = new QCheckBox(gridLayoutWidget);
        ram2->setObjectName("ram2");
        ram2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_6->addWidget(ram2);

        ram3 = new QCheckBox(gridLayoutWidget);
        ram3->setObjectName("ram3");
        ram3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_6->addWidget(ram3);


        gridLayout_3->addLayout(verticalLayout_6, 2, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_42 = new QLabel(gridLayoutWidget);
        label_42->setObjectName("label_42");
        label_42->setMinimumSize(QSize(0, 27));
        label_42->setFont(font1);
        label_42->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_42->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_4->addWidget(label_42);

        label_43 = new QLabel(gridLayoutWidget);
        label_43->setObjectName("label_43");
        label_43->setMinimumSize(QSize(0, 20));
        label_43->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_43->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_4->addWidget(label_43);

        mp1 = new QCheckBox(gridLayoutWidget);
        mp1->setObjectName("mp1");
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        mp1->setPalette(palette1);
        mp1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(mp1);

        mp2 = new QCheckBox(gridLayoutWidget);
        mp2->setObjectName("mp2");
        mp2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(mp2);

        mp3 = new QCheckBox(gridLayoutWidget);
        mp3->setObjectName("mp3");
        mp3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(mp3);

        label_45 = new QLabel(gridLayoutWidget);
        label_45->setObjectName("label_45");
        label_45->setMinimumSize(QSize(0, 20));
        label_45->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_45->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_4->addWidget(label_45);

        mm1 = new QCheckBox(gridLayoutWidget);
        mm1->setObjectName("mm1");
        mm1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(mm1);

        mm2 = new QCheckBox(gridLayoutWidget);
        mm2->setObjectName("mm2");
        mm2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(mm2);

        mm3 = new QCheckBox(gridLayoutWidget);
        mm3->setObjectName("mm3");
        mm3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(mm3);

        label_44 = new QLabel(gridLayoutWidget);
        label_44->setObjectName("label_44");
        label_44->setMinimumSize(QSize(24, 27));
        label_44->setFont(font1);
        label_44->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_44->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_4->addWidget(label_44);

        label_47 = new QLabel(gridLayoutWidget);
        label_47->setObjectName("label_47");
        label_47->setMinimumSize(QSize(0, 20));
        label_47->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_47->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_4->addWidget(label_47);

        pp1 = new QCheckBox(gridLayoutWidget);
        pp1->setObjectName("pp1");
        pp1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(pp1);

        pp2 = new QCheckBox(gridLayoutWidget);
        pp2->setObjectName("pp2");
        pp2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(pp2);

        label_56 = new QLabel(gridLayoutWidget);
        label_56->setObjectName("label_56");

        verticalLayout_4->addWidget(label_56);

        label_46 = new QLabel(gridLayoutWidget);
        label_46->setObjectName("label_46");
        label_46->setMinimumSize(QSize(0, 20));
        label_46->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color #332225;\n"
"}"));
        label_46->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_4->addWidget(label_46);

        pm1 = new QCheckBox(gridLayoutWidget);
        pm1->setObjectName("pm1");
        pm1->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(pm1);

        pm2 = new QCheckBox(gridLayoutWidget);
        pm2->setObjectName("pm2");
        pm2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(pm2);

        pm3 = new QCheckBox(gridLayoutWidget);
        pm3->setObjectName("pm3");
        pm3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 20px;\n"
"}"));

        verticalLayout_4->addWidget(pm3);


        gridLayout_3->addLayout(verticalLayout_4, 2, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(629, 195, 691, 431));
        label_3->setStyleSheet(QString::fromUtf8("OLabel {\n"
"	background-color: #9283ac;\n"
"	 border-radius: 10px;\n"
"}"));
        label_54 = new QLabel(centralwidget);
        label_54->setObjectName("label_54");
        label_54->setGeometry(QRect(0, 0, 960, 450));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(150, 21, 421, 601));
        MainWindow->setCentralWidget(centralwidget);
        label_3->raise();
        label_54->raise();
        label_24->raise();
        label_18->raise();
        label_55->raise();
        horizontalLayoutWidget->raise();
        gridLayoutWidget->raise();
        tableWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1343, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\222\320\265\320\273\320\270\320\272\320\270\320\271 \320\272\320\276\320\274\320\261\320\270\320\275\320\260\321\202\320\276\321\200 ", nullptr));
        label_55->setText(QString());
        label_18->setText(QString());
        label_24->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\320\273\321\214\320\272\320\276 \320\262\321\213 \320\263\320\276\321\202\320\276\320\262\321\213 \320\277\320\276\321\202\321\200\320\260\321\202\320\270\321\202\321\214?", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        cp3->setText(QCoreApplication::translate("MainWindow", "Floor Technology Company Ltd", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\200\320\277\321\203\321\201", nullptr));
        cm3->setText(QCoreApplication::translate("MainWindow", "Powercase Mistral X4 Mesh LED", nullptr));
        psm2->setText(QCoreApplication::translate("MainWindow", "DeepCool PK800D", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\221\320\273\320\276\320\272 \320\277\320\270\321\202\320\260\320\275\320\270\321\217", nullptr));
        psm1->setText(QCoreApplication::translate("MainWindow", "Super Flower SF-850F14TP", nullptr));
        cp2->setText(QCoreApplication::translate("MainWindow", "Listan GMBH Company KG", nullptr));
        cm1->setText(QCoreApplication::translate("MainWindow", "Ginzzu D350", nullptr));
        psm3->setText(QCoreApplication::translate("MainWindow", "be quiet! System Power 9", nullptr));
        psp1->setText(QCoreApplication::translate("MainWindow", "Super Flower Computer Inc", nullptr));
        cp1->setText(QCoreApplication::translate("MainWindow", "Ginzu Technology Limited", nullptr));
        psp3->setText(QCoreApplication::translate("MainWindow", "Listan GMBH Company KG.", nullptr));
        psp2->setText(QCoreApplication::translate("MainWindow", "Beijing Deepcool Industries", nullptr));
        cm2->setText(QCoreApplication::translate("MainWindow", "PURE BASE 500DX BGW37", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\272\320\276\320\277\320\270\321\202\320\265\320\273\321\214", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214", nullptr));
        hdp1->setText(QCoreApplication::translate("MainWindow", "Kingston Technology Company", nullptr));
        hdp2->setText(QCoreApplication::translate("MainWindow", "Netac Technology Co.", nullptr));
        label_57->setText(QString());
        label_49->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        hdm1->setText(QCoreApplication::translate("MainWindow", "RAM Kingston FURY Beast 2x8GB", nullptr));
        hdm2->setText(QCoreApplication::translate("MainWindow", "Netac Basic 4GB DDR3 PC3-12800 ", nullptr));
        hdm3->setText(QCoreApplication::translate("MainWindow", "Netac Basic 16GB NTBSD4P32SP", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\321\202\320\270\320\262\320\275\320\260\321\217 \320\277\320\260\320\274\321\217\321\202\321\214", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214", nullptr));
        rap1->setText(QCoreApplication::translate("MainWindow", "Western Digital Technologies", nullptr));
        rap2->setText(QCoreApplication::translate("MainWindow", "Seagate Technology LLC", nullptr));
        label_58->setText(QString());
        label_53->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        ram1->setText(QCoreApplication::translate("MainWindow", "WD Purple 2TB WD22PURZ", nullptr));
        ram2->setText(QCoreApplication::translate("MainWindow", "WD Blue 6TB WD60EZAZ", nullptr));
        ram3->setText(QCoreApplication::translate("MainWindow", "Seagate BarraCuda 1TB ", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\265\321\200\320\270\320\275\321\201\320\272\320\260\321\217 \320\277\320\273\320\260\321\202\320\260", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214", nullptr));
        mp1->setText(QCoreApplication::translate("MainWindow", "Asrock INC", nullptr));
        mp2->setText(QCoreApplication::translate("MainWindow", "Gigabyte Technology Company", nullptr));
        mp3->setText(QCoreApplication::translate("MainWindow", "Micro-Star International", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        mm1->setText(QCoreApplication::translate("MainWindow", "ASRock B660M Pro RS", nullptr));
        mm2->setText(QCoreApplication::translate("MainWindow", "Gigabyte B450M H (rev. 1.0)", nullptr));
        mm3->setText(QCoreApplication::translate("MainWindow", "MSI MAG B550 Tomahawk", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\321\201\321\201\320\276\321\200", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214", nullptr));
        pp1->setText(QCoreApplication::translate("MainWindow", "Intel Corporation", nullptr));
        pp2->setText(QCoreApplication::translate("MainWindow", "Advanced Micro Devices", nullptr));
        label_56->setText(QString());
        label_46->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        pm1->setText(QCoreApplication::translate("MainWindow", "Intel Core i5-12400F", nullptr));
        pm2->setText(QCoreApplication::translate("MainWindow", "AMD Ryzen 5 5600X", nullptr));
        pm3->setText(QCoreApplication::translate("MainWindow", "AMD Ryzen 7 5700G", nullptr));
        label_3->setText(QString());
        label_54->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
