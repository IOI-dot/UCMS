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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Student_Login
{
public:
    QLabel *student_login_label;
    QLabel *student_username_login_label;
    QLineEdit *student_username_login_lineEdit;
    QLabel *student_password_login_label;
    QLineEdit *student_password_login_lineEdit;
    QPushButton *student_login_pushButton;
    QLabel *new_user_label;
    QPushButton *student_register_pushButton;

    void setupUi(QDialog *Student_Login)
    {
        if (Student_Login->objectName().isEmpty())
            Student_Login->setObjectName("Student_Login");
        Student_Login->resize(409, 444);
        student_login_label = new QLabel(Student_Login);
        student_login_label->setObjectName("student_login_label");
        student_login_label->setGeometry(QRect(50, 50, 81, 16));
        student_username_login_label = new QLabel(Student_Login);
        student_username_login_label->setObjectName("student_username_login_label");
        student_username_login_label->setGeometry(QRect(50, 80, 71, 16));
        student_username_login_lineEdit = new QLineEdit(Student_Login);
        student_username_login_lineEdit->setObjectName("student_username_login_lineEdit");
        student_username_login_lineEdit->setGeometry(QRect(50, 110, 113, 24));
        student_password_login_label = new QLabel(Student_Login);
        student_password_login_label->setObjectName("student_password_login_label");
        student_password_login_label->setGeometry(QRect(50, 150, 71, 16));
        student_password_login_lineEdit = new QLineEdit(Student_Login);
        student_password_login_lineEdit->setObjectName("student_password_login_lineEdit");
        student_password_login_lineEdit->setGeometry(QRect(50, 180, 113, 24));
        student_password_login_lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        student_login_pushButton = new QPushButton(Student_Login);
        student_login_pushButton->setObjectName("student_login_pushButton");
        student_login_pushButton->setGeometry(QRect(50, 240, 80, 24));
        new_user_label = new QLabel(Student_Login);
        new_user_label->setObjectName("new_user_label");
        new_user_label->setGeometry(QRect(50, 320, 181, 16));
        student_register_pushButton = new QPushButton(Student_Login);
        student_register_pushButton->setObjectName("student_register_pushButton");
        student_register_pushButton->setGeometry(QRect(50, 350, 80, 24));

        retranslateUi(Student_Login);

        QMetaObject::connectSlotsByName(Student_Login);
    } // setupUi

    void retranslateUi(QDialog *Student_Login)
    {
        Student_Login->setWindowTitle(QCoreApplication::translate("Student_Login", "Dialog", nullptr));
        student_login_label->setText(QCoreApplication::translate("Student_Login", "Student Login", nullptr));
        student_username_login_label->setText(QCoreApplication::translate("Student_Login", "Username:", nullptr));
        student_password_login_label->setText(QCoreApplication::translate("Student_Login", "Password:", nullptr));
        student_login_pushButton->setText(QCoreApplication::translate("Student_Login", "Login", nullptr));
        new_user_label->setText(QCoreApplication::translate("Student_Login", "New User? Create a new account!", nullptr));
        student_register_pushButton->setText(QCoreApplication::translate("Student_Login", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student_Login: public Ui_Student_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_LOGIN_H
