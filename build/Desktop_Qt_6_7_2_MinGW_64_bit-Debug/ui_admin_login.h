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

QT_BEGIN_NAMESPACE

class Ui_Admin_Login
{
public:

    void setupUi(QDialog *Admin_Login)
    {
        if (Admin_Login->objectName().isEmpty())
            Admin_Login->setObjectName("Admin_Login");
        Admin_Login->resize(400, 300);

        retranslateUi(Admin_Login);

        QMetaObject::connectSlotsByName(Admin_Login);
    } // setupUi

    void retranslateUi(QDialog *Admin_Login)
    {
        Admin_Login->setWindowTitle(QCoreApplication::translate("Admin_Login", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin_Login: public Ui_Admin_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_LOGIN_H
