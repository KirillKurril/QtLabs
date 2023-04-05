/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QLabel *formulaLabel;
    QTextBrowser *textBrowser;
    QLabel *variableLabelA;
    QLabel *variableLabelB;
    QLabel *variableLabelC;
    QLabel *variableLabelD;
    QLabel *variableLabelE;
    QLabel *formulaLabel_2;
    QLineEdit *formulaEdit;
    QLabel *label;
    QDoubleSpinBox *variableEditA;
    QDoubleSpinBox *variableEditB;
    QDoubleSpinBox *variableEditC;
    QDoubleSpinBox *variableEditD;
    QDoubleSpinBox *variableEditE;
    QPushButton *evaluate1;
    QPushButton *evaluate2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(820, 121);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
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
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(200, 10, 101, 41));
        QFont font;
        font.setPointSize(8);
        comboBox->setFont(font);
        formulaLabel = new QLabel(centralwidget);
        formulaLabel->setObjectName(QString::fromUtf8("formulaLabel"));
        formulaLabel->setGeometry(QRect(10, 10, 181, 41));
        formulaLabel->setFont(font);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(460, 70, 350, 41));
        variableLabelA = new QLabel(centralwidget);
        variableLabelA->setObjectName(QString::fromUtf8("variableLabelA"));
        variableLabelA->setGeometry(QRect(420, 10, 21, 41));
        variableLabelB = new QLabel(centralwidget);
        variableLabelB->setObjectName(QString::fromUtf8("variableLabelB"));
        variableLabelB->setGeometry(QRect(500, 10, 21, 41));
        variableLabelC = new QLabel(centralwidget);
        variableLabelC->setObjectName(QString::fromUtf8("variableLabelC"));
        variableLabelC->setGeometry(QRect(580, 10, 21, 41));
        variableLabelD = new QLabel(centralwidget);
        variableLabelD->setObjectName(QString::fromUtf8("variableLabelD"));
        variableLabelD->setGeometry(QRect(660, 10, 21, 41));
        variableLabelE = new QLabel(centralwidget);
        variableLabelE->setObjectName(QString::fromUtf8("variableLabelE"));
        variableLabelE->setGeometry(QRect(740, 10, 21, 41));
        formulaLabel_2 = new QLabel(centralwidget);
        formulaLabel_2->setObjectName(QString::fromUtf8("formulaLabel_2"));
        formulaLabel_2->setGeometry(QRect(10, 70, 181, 41));
        formulaLabel_2->setFont(font);
        formulaEdit = new QLineEdit(centralwidget);
        formulaEdit->setObjectName(QString::fromUtf8("formulaEdit"));
        formulaEdit->setGeometry(QRect(200, 70, 101, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(420, 70, 41, 41));
        variableEditA = new QDoubleSpinBox(centralwidget);
        variableEditA->setObjectName(QString::fromUtf8("variableEditA"));
        variableEditA->setGeometry(QRect(440, 10, 51, 41));
        variableEditB = new QDoubleSpinBox(centralwidget);
        variableEditB->setObjectName(QString::fromUtf8("variableEditB"));
        variableEditB->setGeometry(QRect(520, 10, 51, 41));
        variableEditC = new QDoubleSpinBox(centralwidget);
        variableEditC->setObjectName(QString::fromUtf8("variableEditC"));
        variableEditC->setGeometry(QRect(600, 10, 51, 41));
        variableEditD = new QDoubleSpinBox(centralwidget);
        variableEditD->setObjectName(QString::fromUtf8("variableEditD"));
        variableEditD->setGeometry(QRect(680, 10, 51, 41));
        variableEditE = new QDoubleSpinBox(centralwidget);
        variableEditE->setObjectName(QString::fromUtf8("variableEditE"));
        variableEditE->setGeometry(QRect(760, 10, 51, 41));
        evaluate1 = new QPushButton(centralwidget);
        evaluate1->setObjectName(QString::fromUtf8("evaluate1"));
        evaluate1->setGeometry(QRect(310, 10, 81, 41));
        evaluate2 = new QPushButton(centralwidget);
        evaluate2->setObjectName(QString::fromUtf8("evaluate2"));
        evaluate2->setGeometry(QRect(310, 70, 81, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
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

        formulaLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\321\216\321\211\320\265\320\263\320\276 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\321\217:", nullptr));
        variableLabelA->setText(QCoreApplication::translate("MainWindow", "a =", nullptr));
        variableLabelB->setText(QCoreApplication::translate("MainWindow", "b =", nullptr));
        variableLabelC->setText(QCoreApplication::translate("MainWindow", "c =", nullptr));
        variableLabelD->setText(QCoreApplication::translate("MainWindow", "d =", nullptr));
        variableLabelE->setText(QCoreApplication::translate("MainWindow", "e =", nullptr));
        formulaLabel_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \321\201\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\263\320\276 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\321\217:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
        evaluate1->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        evaluate2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
