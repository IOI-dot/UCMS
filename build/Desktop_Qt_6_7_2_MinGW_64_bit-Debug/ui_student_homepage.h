/********************************************************************************
** Form generated from reading UI file 'student_homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_HOMEPAGE_H
#define UI_STUDENT_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_student_homepage
{
public:
    QLabel *student_choose_label;
    QPushButton *course_regis_pushButton;
    QPushButton *event_regis_pushButton;
    QPushButton *academic_profile_pushButton;

    void setupUi(QDialog *student_homepage)
    {
        if (student_homepage->objectName().isEmpty())
            student_homepage->setObjectName("student_homepage");
        student_homepage->resize(715, 352);
        student_choose_label = new QLabel(student_homepage);
        student_choose_label->setObjectName("student_choose_label");
        student_choose_label->setGeometry(QRect(290, 40, 101, 16));
        course_regis_pushButton = new QPushButton(student_homepage);
        course_regis_pushButton->setObjectName("course_regis_pushButton");
        course_regis_pushButton->setGeometry(QRect(50, 100, 121, 24));
        event_regis_pushButton = new QPushButton(student_homepage);
        event_regis_pushButton->setObjectName("event_regis_pushButton");
        event_regis_pushButton->setGeometry(QRect(270, 100, 121, 24));
        academic_profile_pushButton = new QPushButton(student_homepage);
        academic_profile_pushButton->setObjectName("academic_profile_pushButton");
        academic_profile_pushButton->setGeometry(QRect(510, 100, 141, 24));

        retranslateUi(student_homepage);

        QMetaObject::connectSlotsByName(student_homepage);
    } // setupUi

    void retranslateUi(QDialog *student_homepage)
    {
        student_homepage->setWindowTitle(QCoreApplication::translate("student_homepage", "Dialog", nullptr));
        student_choose_label->setText(QCoreApplication::translate("student_homepage", "Choose Service:", nullptr));
        course_regis_pushButton->setText(QCoreApplication::translate("student_homepage", "Course Registration", nullptr));
        event_regis_pushButton->setText(QCoreApplication::translate("student_homepage", "Event Registration", nullptr));
        academic_profile_pushButton->setText(QCoreApplication::translate("student_homepage", "View Academic Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class student_homepage: public Ui_student_homepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_HOMEPAGE_H
