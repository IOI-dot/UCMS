/********************************************************************************
** Form generated from reading UI file 'student_course_registration.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_COURSE_REGISTRATION_H
#define UI_STUDENT_COURSE_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Student_Course_Registration
{
public:

    void setupUi(QDialog *Student_Course_Registration)
    {
        if (Student_Course_Registration->objectName().isEmpty())
            Student_Course_Registration->setObjectName("Student_Course_Registration");
        Student_Course_Registration->resize(1026, 685);

        retranslateUi(Student_Course_Registration);

        QMetaObject::connectSlotsByName(Student_Course_Registration);
    } // setupUi

    void retranslateUi(QDialog *Student_Course_Registration)
    {
        Student_Course_Registration->setWindowTitle(QCoreApplication::translate("Student_Course_Registration", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student_Course_Registration: public Ui_Student_Course_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_COURSE_REGISTRATION_H
