/********************************************************************************
** Form generated from reading UI file 'student_login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_LOGIN_H
#define UI_STUDENT_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Student_Login
{
public:

    void setupUi(QDialog *Student_Login)
    {
        if (Student_Login->objectName().isEmpty())
            Student_Login->setObjectName("Student_Login");
        Student_Login->resize(400, 300);

        retranslateUi(Student_Login);

        QMetaObject::connectSlotsByName(Student_Login);
    } // setupUi

    void retranslateUi(QDialog *Student_Login)
    {
        Student_Login->setWindowTitle(QCoreApplication::translate("Student_Login", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student_Login: public Ui_Student_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_LOGIN_H
