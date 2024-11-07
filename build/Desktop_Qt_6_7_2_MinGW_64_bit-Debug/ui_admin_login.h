/********************************************************************************
** Form generated from reading UI file 'admin_login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_LOGIN_H
#define UI_ADMIN_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Admin_Login
{
public:
    QLabel *admin_login_label;
    QLabel *admin_username_label;
    QLineEdit *admin_username_lineEdit;
    QLabel *admin_password_label;
    QLineEdit *admin_password_lineEdit;
    QPushButton *admin_login_pushButton;

    void setupUi(QDialog *Admin_Login)
    {
        if (Admin_Login->objectName().isEmpty())
            Admin_Login->setObjectName("Admin_Login");
        Admin_Login->resize(400, 300);
        admin_login_label = new QLabel(Admin_Login);
        admin_login_label->setObjectName("admin_login_label");
        admin_login_label->setGeometry(QRect(20, 20, 81, 16));
        admin_username_label = new QLabel(Admin_Login);
        admin_username_label->setObjectName("admin_username_label");
        admin_username_label->setGeometry(QRect(20, 60, 71, 16));
        admin_username_lineEdit = new QLineEdit(Admin_Login);
        admin_username_lineEdit->setObjectName("admin_username_lineEdit");
        admin_username_lineEdit->setGeometry(QRect(20, 90, 113, 24));
        admin_password_label = new QLabel(Admin_Login);
        admin_password_label->setObjectName("admin_password_label");
        admin_password_label->setGeometry(QRect(20, 150, 61, 16));
        admin_password_lineEdit = new QLineEdit(Admin_Login);
        admin_password_lineEdit->setObjectName("admin_password_lineEdit");
        admin_password_lineEdit->setGeometry(QRect(20, 180, 113, 24));
        admin_password_lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        admin_login_pushButton = new QPushButton(Admin_Login);
        admin_login_pushButton->setObjectName("admin_login_pushButton");
        admin_login_pushButton->setGeometry(QRect(280, 240, 80, 24));

        retranslateUi(Admin_Login);

        QMetaObject::connectSlotsByName(Admin_Login);
    } // setupUi

    void retranslateUi(QDialog *Admin_Login)
    {
        Admin_Login->setWindowTitle(QCoreApplication::translate("Admin_Login", "Dialog", nullptr));
        admin_login_label->setText(QCoreApplication::translate("Admin_Login", "Admin Login", nullptr));
        admin_username_label->setText(QCoreApplication::translate("Admin_Login", "Username:", nullptr));
        admin_password_label->setText(QCoreApplication::translate("Admin_Login", "Password:", nullptr));
        admin_login_pushButton->setText(QCoreApplication::translate("Admin_Login", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin_Login: public Ui_Admin_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_LOGIN_H
