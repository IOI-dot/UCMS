#include "student_course_registration.h"
#include "ui_student_course_registration.h"

Student_Course_Registration::Student_Course_Registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Student_Course_Registration)
{
    ui->setupUi(this);
}

Student_Course_Registration::~Student_Course_Registration()
{
    delete ui;
}
