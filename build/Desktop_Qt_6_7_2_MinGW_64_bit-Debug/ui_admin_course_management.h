/********************************************************************************
** Form generated from reading UI file 'admin_course_management.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_COURSE_MANAGEMENT_H
#define UI_ADMIN_COURSE_MANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_admin_course_management
{
public:

    void setupUi(QDialog *admin_course_management)
    {
        if (admin_course_management->objectName().isEmpty())
            admin_course_management->setObjectName("admin_course_management");
        admin_course_management->resize(1024, 686);

        retranslateUi(admin_course_management);

        QMetaObject::connectSlotsByName(admin_course_management);
    } // setupUi

    void retranslateUi(QDialog *admin_course_management)
    {
        admin_course_management->setWindowTitle(QCoreApplication::translate("admin_course_management", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_course_management: public Ui_admin_course_management {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_COURSE_MANAGEMENT_H
