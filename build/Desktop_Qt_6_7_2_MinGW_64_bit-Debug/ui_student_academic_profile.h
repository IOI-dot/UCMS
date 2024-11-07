/********************************************************************************
** Form generated from reading UI file 'student_academic_profile.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_ACADEMIC_PROFILE_H
#define UI_STUDENT_ACADEMIC_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_student_academic_profile
{
public:

    void setupUi(QDialog *student_academic_profile)
    {
        if (student_academic_profile->objectName().isEmpty())
            student_academic_profile->setObjectName("student_academic_profile");
        student_academic_profile->resize(1026, 684);

        retranslateUi(student_academic_profile);

        QMetaObject::connectSlotsByName(student_academic_profile);
    } // setupUi

    void retranslateUi(QDialog *student_academic_profile)
    {
        student_academic_profile->setWindowTitle(QCoreApplication::translate("student_academic_profile", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class student_academic_profile: public Ui_student_academic_profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_ACADEMIC_PROFILE_H
