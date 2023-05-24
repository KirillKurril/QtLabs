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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *local_vars;
    QPushButton *structs_button;
    QPushButton *vars_button;
    QPushButton *open_file_button;
    QPushButton *prototypes_button;
    QPushButton *changes_button;
    QPushButton *overloads_button;
    QPushButton *depth_button;
    QPushButton *logic_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(672, 384);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(20, 20, 611, 201));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 240, 611, 86));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        local_vars = new QPushButton(gridLayoutWidget);
        local_vars->setObjectName("local_vars");

        gridLayout->addWidget(local_vars, 1, 2, 1, 1);

        structs_button = new QPushButton(gridLayoutWidget);
        structs_button->setObjectName("structs_button");

        gridLayout->addWidget(structs_button, 0, 2, 1, 1);

        vars_button = new QPushButton(gridLayoutWidget);
        vars_button->setObjectName("vars_button");

        gridLayout->addWidget(vars_button, 0, 1, 1, 1);

        open_file_button = new QPushButton(gridLayoutWidget);
        open_file_button->setObjectName("open_file_button");

        gridLayout->addWidget(open_file_button, 0, 0, 1, 1);

        prototypes_button = new QPushButton(gridLayoutWidget);
        prototypes_button->setObjectName("prototypes_button");

        gridLayout->addWidget(prototypes_button, 1, 0, 1, 1);

        changes_button = new QPushButton(gridLayoutWidget);
        changes_button->setObjectName("changes_button");

        gridLayout->addWidget(changes_button, 1, 1, 1, 1);

        overloads_button = new QPushButton(gridLayoutWidget);
        overloads_button->setObjectName("overloads_button");

        gridLayout->addWidget(overloads_button, 2, 0, 1, 1);

        depth_button = new QPushButton(gridLayoutWidget);
        depth_button->setObjectName("depth_button");

        gridLayout->addWidget(depth_button, 2, 1, 1, 1);

        logic_button = new QPushButton(gridLayoutWidget);
        logic_button->setObjectName("logic_button");

        gridLayout->addWidget(logic_button, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 672, 22));
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
        local_vars->setText(QCoreApplication::translate("MainWindow", "Local vars", nullptr));
        structs_button->setText(QCoreApplication::translate("MainWindow", "Structs", nullptr));
        vars_button->setText(QCoreApplication::translate("MainWindow", "Vars", nullptr));
        open_file_button->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        prototypes_button->setText(QCoreApplication::translate("MainWindow", "Prototypes", nullptr));
        changes_button->setText(QCoreApplication::translate("MainWindow", "Changes", nullptr));
        overloads_button->setText(QCoreApplication::translate("MainWindow", "Overloads", nullptr));
        depth_button->setText(QCoreApplication::translate("MainWindow", "Depth", nullptr));
        logic_button->setText(QCoreApplication::translate("MainWindow", "LogicErrors", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
