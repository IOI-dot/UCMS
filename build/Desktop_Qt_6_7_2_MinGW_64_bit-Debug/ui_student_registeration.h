/********************************************************************************
** Form generated from reading UI file 'student_registeration.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_REGISTERATION_H
#define UI_STUDENT_REGISTERATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Student_Registeration
{
public:

    void setupUi(QDialog *Student_Registeration)
    {
        if (Student_Registeration->objectName().isEmpty())
            Student_Registeration->setObjectName("Student_Registeration");
        Student_Registeration->resize(400, 300);

        retranslateUi(Student_Registeration);

        QMetaObject::connectSlotsByName(Student_Registeration);
    } // setupUi

    void retranslateUi(QDialog *Student_Registeration)
    {
        Student_Registeration->setWindowTitle(QCoreApplication::translate("Student_Registeration", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student_Registeration: public Ui_Student_Registeration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_REGISTERATION_H
