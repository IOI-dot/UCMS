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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Student_Registeration
{
public:
    QLabel *registration_label;
    QLabel *full_name_label;
    QLineEdit *full_name_lineEdit;
    QLabel *email_label;
    QLineEdit *email_lineEdit;
    QLabel *UID_label;
    QLineEdit *UID_lineEdit;
    QLabel *Password_regist_label;
    QLineEdit *password_regis_lineEdit;
    QPushButton *sign_up_pushButton;

    void setupUi(QDialog *Student_Registeration)
    {
        if (Student_Registeration->objectName().isEmpty())
            Student_Registeration->setObjectName("Student_Registeration");
        Student_Registeration->resize(436, 465);
        registration_label = new QLabel(Student_Registeration);
        registration_label->setObjectName("registration_label");
        registration_label->setGeometry(QRect(20, 30, 101, 16));
        full_name_label = new QLabel(Student_Registeration);
        full_name_label->setObjectName("full_name_label");
        full_name_label->setGeometry(QRect(20, 70, 71, 16));
        full_name_lineEdit = new QLineEdit(Student_Registeration);
        full_name_lineEdit->setObjectName("full_name_lineEdit");
        full_name_lineEdit->setGeometry(QRect(20, 100, 113, 24));
        email_label = new QLabel(Student_Registeration);
        email_label->setObjectName("email_label");
        email_label->setGeometry(QRect(20, 140, 49, 16));
        email_lineEdit = new QLineEdit(Student_Registeration);
        email_lineEdit->setObjectName("email_lineEdit");
        email_lineEdit->setGeometry(QRect(20, 170, 113, 24));
        UID_label = new QLabel(Student_Registeration);
        UID_label->setObjectName("UID_label");
        UID_label->setGeometry(QRect(20, 210, 49, 16));
        UID_lineEdit = new QLineEdit(Student_Registeration);
        UID_lineEdit->setObjectName("UID_lineEdit");
        UID_lineEdit->setGeometry(QRect(20, 240, 113, 24));
        Password_regist_label = new QLabel(Student_Registeration);
        Password_regist_label->setObjectName("Password_regist_label");
        Password_regist_label->setGeometry(QRect(20, 280, 61, 16));
        password_regis_lineEdit = new QLineEdit(Student_Registeration);
        password_regis_lineEdit->setObjectName("password_regis_lineEdit");
        password_regis_lineEdit->setGeometry(QRect(20, 310, 113, 24));
        password_regis_lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        sign_up_pushButton = new QPushButton(Student_Registeration);
        sign_up_pushButton->setObjectName("sign_up_pushButton");
        sign_up_pushButton->setGeometry(QRect(310, 370, 80, 24));

        retranslateUi(Student_Registeration);

        QMetaObject::connectSlotsByName(Student_Registeration);
    } // setupUi

    void retranslateUi(QDialog *Student_Registeration)
    {
        Student_Registeration->setWindowTitle(QCoreApplication::translate("Student_Registeration", "Dialog", nullptr));
        registration_label->setText(QCoreApplication::translate("Student_Registeration", "Registration Form", nullptr));
        full_name_label->setText(QCoreApplication::translate("Student_Registeration", "Full Name:", nullptr));
        email_label->setText(QCoreApplication::translate("Student_Registeration", "Email:", nullptr));
        UID_label->setText(QCoreApplication::translate("Student_Registeration", "UID:", nullptr));
        Password_regist_label->setText(QCoreApplication::translate("Student_Registeration", "Password:", nullptr));
        sign_up_pushButton->setText(QCoreApplication::translate("Student_Registeration", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student_Registeration: public Ui_Student_Registeration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_REGISTERATION_H
