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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *lineEditD;
    QSpacerItem *verticalSpacer_7;
    QLineEdit *lineEditC;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *lineEditB;
    QLabel *label_2;
    QLineEdit *lineEditA;
    QLineEdit *lineEditE;
    QSpacerItem *verticalSpacer_5;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *formulaLabel;
    QComboBox *comboBox;
    QPushButton *evaluate1;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *formulaLabel_2;
    QLineEdit *formulaEdit;
    QPushButton *evaluate2;
    QSpacerItem *verticalSpacer_3;
    QTextBrowser *textBrowser;
    QLabel *kit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(515, 655);
        MainWindow->setMinimumSize(QSize(515, 0));
        MainWindow->setMaximumSize(QSize(515, 699999));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 501, 61));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        QFont font;
        font.setPointSize(20);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 70, 241, 321));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 3, 0, 1, 1);

        lineEditD = new QLineEdit(gridLayoutWidget);
        lineEditD->setObjectName("lineEditD");

        gridLayout_2->addWidget(lineEditD, 6, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 1, 0, 1, 1);

        lineEditC = new QLineEdit(gridLayoutWidget);
        lineEditC->setObjectName("lineEditC");

        gridLayout_2->addWidget(lineEditC, 4, 1, 1, 1, Qt::AlignTop);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 8, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 7, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 6, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        lineEditB = new QLineEdit(gridLayoutWidget);
        lineEditB->setObjectName("lineEditB");

        gridLayout_2->addWidget(lineEditB, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1, Qt::AlignTop);

        lineEditA = new QLineEdit(gridLayoutWidget);
        lineEditA->setObjectName("lineEditA");

        gridLayout_2->addWidget(lineEditA, 0, 1, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        lineEditE = new QLineEdit(gridLayoutWidget);
        lineEditE->setObjectName("lineEditE");

        gridLayout_2->addWidget(lineEditE, 8, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 5, 0, 1, 1);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(279, 70, 233, 321));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        formulaLabel = new QLabel(verticalLayoutWidget_4);
        formulaLabel->setObjectName("formulaLabel");
        QFont font1;
        font1.setPointSize(8);
        formulaLabel->setFont(font1);

        verticalLayout_2->addWidget(formulaLabel);

        comboBox = new QComboBox(verticalLayoutWidget_4);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font1);

        verticalLayout_2->addWidget(comboBox);

        evaluate1 = new QPushButton(verticalLayoutWidget_4);
        evaluate1->setObjectName("evaluate1");

        verticalLayout_2->addWidget(evaluate1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        formulaLabel_2 = new QLabel(verticalLayoutWidget_4);
        formulaLabel_2->setObjectName("formulaLabel_2");
        formulaLabel_2->setFont(font1);

        verticalLayout_3->addWidget(formulaLabel_2);

        formulaEdit = new QLineEdit(verticalLayoutWidget_4);
        formulaEdit->setObjectName("formulaEdit");

        verticalLayout_3->addWidget(formulaEdit);

        evaluate2 = new QPushButton(verticalLayoutWidget_4);
        evaluate2->setObjectName("evaluate2");

        verticalLayout_3->addWidget(evaluate2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        textBrowser = new QTextBrowser(verticalLayoutWidget_4);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMinimumSize(QSize(0, 50));
        textBrowser->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(textBrowser);


        verticalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_2);

        kit = new QLabel(centralwidget);
        kit->setObjectName("kit");
        kit->setGeometry(QRect(110, 420, 281, 211));
        kit->setMinimumSize(QSize(281, 0));
        kit->setMaximumSize(QSize(281, 16777215));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Psheprasham :D", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\262\320\265\321\202 \320\270\320\267 \320\237\320\276\320\273\321\214\321\210\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 e", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 b", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 d", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 c", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 a", nullptr));
        formulaLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\321\216\321\211\320\265\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "a/(b-c)*(d+e)", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "(a+b)*(c-d)/e", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "a-(b+c*d)/e", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "a/b-((c+d)*e)", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "a*(b-c+d)/e", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "(a+b)*(c-d)/e", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "a*(b-c)/(d+e)", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "a/(b*(c+d))-e", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "(a+(b/c-d))*e", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "a*(b+c)/(d-e)", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MainWindow", "a-(b/c*(d+e))", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("MainWindow", "(a-b)/(c+d)*e", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("MainWindow", "a/(b+c-d*e)", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("MainWindow", "a*(b-c)/(d+e)", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("MainWindow", "(a+b*c)/(d-e)", nullptr));

        evaluate1->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        formulaLabel_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\321\221 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        evaluate2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", nullptr));
        kit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
