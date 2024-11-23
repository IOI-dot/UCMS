#include "student_academic_profile.h"
#include "ui_student_academic_profile.h"
#include "student.h"
#include "course.h"  // Include the header file where Course is defined

student_academic_profile::student_academic_profile(QWidget *parent, Student& student)
    : QDialog(parent),
    ui(new Ui::student_academic_profile),
    currentStudent(student)  // Store reference to the actual student
{
    ui->setupUi(this);
    displayStudentProfile();  // Populate UI with current student data
}

student_academic_profile::~student_academic_profile() {
    delete ui;
}

void student_academic_profile::displayStudentProfile() {
    // Set the student's name
    ui->namelabel->setText(currentStudent.getUsername());

    // Set the student's ID
    ui->idlabel->setText(currentStudent.getStudentID());

    // Optionally display the student ID in another label (if needed)
    ui->who->setText(currentStudent.getStudentID());

    // Set the student's academic status
    ui->aslabel->setText(currentStudent.getAcademicStatus());

    // Get the list of CRNs registered by the student
    QVector<QString> registeredCoursesCRNs = currentStudent.getRegisteredCourses();

    // Vector to hold the course names or other information to be displayed
    QStringList courseDetails;

    // Loop through the CRNs and fetch details for each course
    for (const QString& crn : registeredCoursesCRNs) {
        bool found = false;
        for (const Course& course : Course::getAllCourses()) {
            if (course.getCourseID() == crn) {  // Ensure correct matching
                // Add the course details to the list (e.g., name and instructor)
                courseDetails.append(course.getName() + " - " + course.getInstructor());
                found = true;
                break;
            }
        }
        if (!found) {
            courseDetails.append("Course not found for CRN: " + crn);  // If course not found in the list
        }
    }

    // Check if courses are registered
    QString courseText;
    if (courseDetails.isEmpty()) {
        courseText = "No courses registered."; // In case the student has no courses
    } else {
        courseText = "Courses Registered: \n" + courseDetails.join("\n");  // Join courses with newline
    }

    // Set the courses label
    ui->courselabel->setText(courseText);
}

