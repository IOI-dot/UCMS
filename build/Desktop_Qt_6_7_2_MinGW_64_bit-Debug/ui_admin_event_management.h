/********************************************************************************
** Form generated from reading UI file 'admin_event_management.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_EVENT_MANAGEMENT_H
#define UI_ADMIN_EVENT_MANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_admin_event_management
{
public:

    void setupUi(QDialog *admin_event_management)
    {
        if (admin_event_management->objectName().isEmpty())
            admin_event_management->setObjectName("admin_event_management");
        admin_event_management->resize(1025, 685);

        retranslateUi(admin_event_management);

        QMetaObject::connectSlotsByName(admin_event_management);
    } // setupUi

    void retranslateUi(QDialog *admin_event_management)
    {
        admin_event_management->setWindowTitle(QCoreApplication::translate("admin_event_management", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_event_management: public Ui_admin_event_management {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_EVENT_MANAGEMENT_H
