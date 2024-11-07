/********************************************************************************
** Form generated from reading UI file 'admin_homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_HOMEPAGE_H
#define UI_ADMIN_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_admin_homepage
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *admin_homepage)
    {
        if (admin_homepage->objectName().isEmpty())
            admin_homepage->setObjectName("admin_homepage");
        admin_homepage->resize(678, 469);
        label = new QLabel(admin_homepage);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 40, 101, 16));
        pushButton = new QPushButton(admin_homepage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 90, 131, 24));
        pushButton_2 = new QPushButton(admin_homepage);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 90, 131, 24));
        pushButton_3 = new QPushButton(admin_homepage);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(450, 90, 121, 24));

        retranslateUi(admin_homepage);

        QMetaObject::connectSlotsByName(admin_homepage);
    } // setupUi

    void retranslateUi(QDialog *admin_homepage)
    {
        admin_homepage->setWindowTitle(QCoreApplication::translate("admin_homepage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("admin_homepage", "Choose service:", nullptr));
        pushButton->setText(QCoreApplication::translate("admin_homepage", "Course Management", nullptr));
        pushButton_2->setText(QCoreApplication::translate("admin_homepage", "Student Management", nullptr));
        pushButton_3->setText(QCoreApplication::translate("admin_homepage", "Event Management", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_homepage: public Ui_admin_homepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_HOMEPAGE_H
