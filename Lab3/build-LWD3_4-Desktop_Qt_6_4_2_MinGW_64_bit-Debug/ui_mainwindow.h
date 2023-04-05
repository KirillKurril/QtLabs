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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *push_back_button;
    QPlainTextEdit *plainTextEdit_10;
    QPushButton *size_button;
    QTextEdit *textEdit_5;
    QPushButton *swap_button;
    QPushButton *insert_button;
    QPushButton *emplace_back_button;
    QPushButton *erase_button;
    QTextEdit *textEdit_6;
    QPushButton *emplace_button;
    QPushButton *empty_button;
    QTextEdit *textEdit;
    QPushButton *assign_button;
    QPushButton *max_size_button;
    QTextEdit *textEdit_4;
    QPushButton *clear_button;
    QTextEdit *textEdit_8;
    QTextEdit *textEdit_7;
    QPushButton *pushButton;
    QPushButton *capacity_button;
    QPushButton *pushButton_2;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QPushButton *pop_back_button;
    QPlainTextEdit *plainTextEdit_4;
    QPlainTextEdit *plainTextEdit_8;
    QPlainTextEdit *plainTextEdit_12;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 681, 869));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        push_back_button = new QPushButton(gridLayoutWidget);
        push_back_button->setObjectName("push_back_button");

        gridLayout->addWidget(push_back_button, 9, 0, 1, 1);

        plainTextEdit_10 = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit_10->setObjectName("plainTextEdit_10");

        gridLayout->addWidget(plainTextEdit_10, 16, 1, 1, 1);

        size_button = new QPushButton(gridLayoutWidget);
        size_button->setObjectName("size_button");

        gridLayout->addWidget(size_button, 16, 0, 1, 1);

        textEdit_5 = new QTextEdit(gridLayoutWidget);
        textEdit_5->setObjectName("textEdit_5");

        gridLayout->addWidget(textEdit_5, 12, 2, 1, 1);

        swap_button = new QPushButton(gridLayoutWidget);
        swap_button->setObjectName("swap_button");

        gridLayout->addWidget(swap_button, 3, 0, 1, 1);

        insert_button = new QPushButton(gridLayoutWidget);
        insert_button->setObjectName("insert_button");

        gridLayout->addWidget(insert_button, 12, 0, 1, 1);

        emplace_back_button = new QPushButton(gridLayoutWidget);
        emplace_back_button->setObjectName("emplace_back_button");

        gridLayout->addWidget(emplace_back_button, 15, 0, 1, 1);

        erase_button = new QPushButton(gridLayoutWidget);
        erase_button->setObjectName("erase_button");

        gridLayout->addWidget(erase_button, 6, 0, 1, 1);

        textEdit_6 = new QTextEdit(gridLayoutWidget);
        textEdit_6->setObjectName("textEdit_6");

        gridLayout->addWidget(textEdit_6, 13, 1, 1, 1);

        emplace_button = new QPushButton(gridLayoutWidget);
        emplace_button->setObjectName("emplace_button");

        gridLayout->addWidget(emplace_button, 13, 0, 1, 1);

        empty_button = new QPushButton(gridLayoutWidget);
        empty_button->setObjectName("empty_button");

        gridLayout->addWidget(empty_button, 14, 0, 1, 1);

        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);

        assign_button = new QPushButton(gridLayoutWidget);
        assign_button->setObjectName("assign_button");

        gridLayout->addWidget(assign_button, 5, 0, 1, 1);

        max_size_button = new QPushButton(gridLayoutWidget);
        max_size_button->setObjectName("max_size_button");

        gridLayout->addWidget(max_size_button, 2, 0, 1, 1);

        textEdit_4 = new QTextEdit(gridLayoutWidget);
        textEdit_4->setObjectName("textEdit_4");

        gridLayout->addWidget(textEdit_4, 12, 1, 1, 1);

        clear_button = new QPushButton(gridLayoutWidget);
        clear_button->setObjectName("clear_button");

        gridLayout->addWidget(clear_button, 18, 0, 1, 1);

        textEdit_8 = new QTextEdit(gridLayoutWidget);
        textEdit_8->setObjectName("textEdit_8");

        gridLayout->addWidget(textEdit_8, 15, 1, 1, 1);

        textEdit_7 = new QTextEdit(gridLayoutWidget);
        textEdit_7->setObjectName("textEdit_7");

        gridLayout->addWidget(textEdit_7, 13, 2, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        capacity_button = new QPushButton(gridLayoutWidget);
        capacity_button->setObjectName("capacity_button");

        gridLayout->addWidget(capacity_button, 8, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 0, 2, 1, 1);

        textEdit_2 = new QTextEdit(gridLayoutWidget);
        textEdit_2->setObjectName("textEdit_2");

        gridLayout->addWidget(textEdit_2, 1, 2, 1, 1);

        textEdit_3 = new QTextEdit(gridLayoutWidget);
        textEdit_3->setObjectName("textEdit_3");

        gridLayout->addWidget(textEdit_3, 2, 2, 1, 1);

        pop_back_button = new QPushButton(gridLayoutWidget);
        pop_back_button->setObjectName("pop_back_button");

        gridLayout->addWidget(pop_back_button, 4, 0, 1, 1);

        plainTextEdit_4 = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit_4->setObjectName("plainTextEdit_4");

        gridLayout->addWidget(plainTextEdit_4, 6, 2, 1, 1);

        plainTextEdit_8 = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit_8->setObjectName("plainTextEdit_8");

        gridLayout->addWidget(plainTextEdit_8, 8, 2, 1, 1);

        plainTextEdit_12 = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit_12->setObjectName("plainTextEdit_12");

        gridLayout->addWidget(plainTextEdit_12, 9, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        push_back_button->setText(QCoreApplication::translate("MainWindow", "push_back", nullptr));
        size_button->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        swap_button->setText(QCoreApplication::translate("MainWindow", "swap", nullptr));
        insert_button->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        emplace_back_button->setText(QCoreApplication::translate("MainWindow", "emplace_back", nullptr));
        erase_button->setText(QCoreApplication::translate("MainWindow", "erase", nullptr));
        emplace_button->setText(QCoreApplication::translate("MainWindow", "emplace", nullptr));
        empty_button->setText(QCoreApplication::translate("MainWindow", "empty", nullptr));
        assign_button->setText(QCoreApplication::translate("MainWindow", "asiign", nullptr));
        max_size_button->setText(QCoreApplication::translate("MainWindow", "max_size", nullptr));
        clear_button->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\265\321\200\320\262\321\213\320\271 \320\262\320\265\320\272\321\202\320\276\321\200", nullptr));
        capacity_button->setText(QCoreApplication::translate("MainWindow", "capacity", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262\321\202\320\276\321\200\320\276\320\271 \320\262\320\265\320\272\321\202\320\276\321\200", nullptr));
        pop_back_button->setText(QCoreApplication::translate("MainWindow", "pop_back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
