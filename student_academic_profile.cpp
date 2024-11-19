// student_academic_profile.cpp
#include "student_academic_profile.h"
#include "ui_student_academic_profile.h"

student_academic_profile::student_academic_profile(Student* student, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::student_academic_profile),
    student(student)  // Initialize student pointer
{
    ui->setupUi(this);
    populateStudentProfile();  // Call the method to fill the profile with data
}

student_academic_profile::~student_academic_profile()
{
    delete ui;
}

void student_academic_profile::populateStudentProfile() {
    // Assuming student has methods to retrieve the data
    ui->namelabel->setText(student->getUsername());
    ui->idlabel->setText(student->getStudentID());
    ui->aslabel->setText(student->getAcademicStatus());

    QString courseList;
    for (const QString& course : student->getRegisteredCourses()) {
        courseList += course + "\n";  // Add newline between courses
    }
    ui->courselabel->setText(courseList);  // Display the courses
}
