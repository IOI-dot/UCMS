/********************************************************************************
** Form generated from reading UI file 'student_event_registration.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_EVENT_REGISTRATION_H
#define UI_STUDENT_EVENT_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_student_event_registration
{
public:

    void setupUi(QDialog *student_event_registration)
    {
        if (student_event_registration->objectName().isEmpty())
            student_event_registration->setObjectName("student_event_registration");
        student_event_registration->resize(1024, 684);

        retranslateUi(student_event_registration);

        QMetaObject::connectSlotsByName(student_event_registration);
    } // setupUi

    void retranslateUi(QDialog *student_event_registration)
    {
        student_event_registration->setWindowTitle(QCoreApplication::translate("student_event_registration", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class student_event_registration: public Ui_student_event_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_EVENT_REGISTRATION_H
