/********************************************************************************
** Form generated from reading UI file 'admin_student_management.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_STUDENT_MANAGEMENT_H
#define UI_ADMIN_STUDENT_MANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_admin_student_management
{
public:

    void setupUi(QDialog *admin_student_management)
    {
        if (admin_student_management->objectName().isEmpty())
            admin_student_management->setObjectName("admin_student_management");
        admin_student_management->resize(1024, 687);

        retranslateUi(admin_student_management);

        QMetaObject::connectSlotsByName(admin_student_management);
    } // setupUi

    void retranslateUi(QDialog *admin_student_management)
    {
        admin_student_management->setWindowTitle(QCoreApplication::translate("admin_student_management", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_student_management: public Ui_admin_student_management {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_STUDENT_MANAGEMENT_H
