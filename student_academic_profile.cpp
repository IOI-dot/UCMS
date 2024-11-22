#include "student_academic_profile.h"
#include "ui_student_academic_profile.h"
#include "student.h"  // Include the Student class for accessing student data

student_academic_profile::student_academic_profile(QWidget *parent, const Student& student) :
    QDialog(parent),
    ui(new Ui::student_academic_profile),
    currentStudent(student) // Store the provided student data
{
    ui->setupUi(this);  // Set up the UI
    displayStudentProfile(student);  // Display the profile data
}

student_academic_profile::~student_academic_profile()
{
    delete ui;
}

// This function is responsible for populating the UI elements with student data
void student_academic_profile::displayStudentProfile(const Student& student)
{
    // Set the student's name
    ui->namelabel->setText(student.getUsername());

    // Set the student's ID
    ui->idlabel->setText(student.getStudentID());

    ui->who->setText(student.getStudentID());
    // Set the student's academic status
    ui->aslabel->setText(student.getAcademicStatus());

    // Set the registered courses
    QStringList courseList = student.getRegisteredCourses();
    QString courseText = "Courses Registered: \n" + courseList.join("\n");  // Join courses with newline
    ui->courselabel->setText(courseText);  // Set the courses label
}
