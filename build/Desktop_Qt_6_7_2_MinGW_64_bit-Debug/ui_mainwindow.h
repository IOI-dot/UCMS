/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *welcome_main_label;
    QLabel *select_role_label;
    QPushButton *student_pushButton;
    QPushButton *admin_pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(788, 426);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        welcome_main_label = new QLabel(centralwidget);
        welcome_main_label->setObjectName("welcome_main_label");
        welcome_main_label->setGeometry(QRect(230, 40, 311, 21));
        select_role_label = new QLabel(centralwidget);
        select_role_label->setObjectName("select_role_label");
        select_role_label->setGeometry(QRect(310, 110, 131, 16));
        student_pushButton = new QPushButton(centralwidget);
        student_pushButton->setObjectName("student_pushButton");
        student_pushButton->setGeometry(QRect(260, 170, 80, 24));
        admin_pushButton = new QPushButton(centralwidget);
        admin_pushButton->setObjectName("admin_pushButton");
        admin_pushButton->setGeometry(QRect(410, 170, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 788, 21));
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
        welcome_main_label->setText(QCoreApplication::translate("MainWindow", "Welcome to the University Course Management System", nullptr));
        select_role_label->setText(QCoreApplication::translate("MainWindow", "Please select your role:", nullptr));
        student_pushButton->setText(QCoreApplication::translate("MainWindow", "Student", nullptr));
        admin_pushButton->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
