#include "student_homepage.h"
#include "ui_student_homepage.h"
#include "student_course_registration.h"
#include "student_event_registration.h"
#include "student_academic_profile.h"
#include <QMessageBox>  // Include for QMessageBox

extern Student* getCurrentStudent();  // Declare the external getCurrentStudent function

student_homepage::student_homepage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::student_homepage)
{
    ui->setupUi(this);
}

student_homepage::~student_homepage()
{
    delete ui;
}

void student_homepage::on_course_regis_pushButton_clicked()
{
    hide();
    Student_Course_Registration *student_course_registration = new Student_Course_Registration;
    student_course_registration->show();
}

void student_homepage::on_event_regis_pushButton_clicked()
{
    hide();
    student_event_registration *Student_event_registration = new student_event_registration;
    Student_event_registration->show();
}

void student_homepage::on_academic_profile_pushButton_clicked()
{
    return;
}

